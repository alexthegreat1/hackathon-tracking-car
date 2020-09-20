import tkinter as tk
import serial
import time
import sys
import signal
import statistics

# max width and height that would accurately fit on my laptop screen
# 150 * 8 = 1200
# 150 * 7 = 1050
WIDTH = 1200
HEIGHT = 1055

ARENA_SIDE_LENGTH = 1050
# ARENA_X_START = 75
# ARENA_Y_START = 5
# ARENA_X_END = 1125
# ARENA_Y_END = 1055
ARENA_X_START = (WIDTH - ARENA_SIDE_LENGTH) / 2
ARENA_Y_START = HEIGHT - ARENA_SIDE_LENGTH
ARENA_X_END = ARENA_X_START + ARENA_SIDE_LENGTH
ARENA_Y_END = ARENA_Y_START + ARENA_SIDE_LENGTH

# from wheel to wheel, in cm is 25cm
# 25cm * 7
# CAR_WIDTH = 175
# 17cm * 7
CAR_WIDTH = 119
# 24cm * 7
CAR_HEIGHT = 168
# single wheel width, 4cm
WHEEL_WIDTH = 28

COM = "/dev/cu.HC-05-DevB"
# COM = "/dev/cu.usbmodem141401"
BAUD = 9600
SerialPort = serial.Serial(COM,BAUD,timeout=1)

points_list = []
car_queue = []
car_history = []

# carDirection = 0 # 0 = right, 1 = down, 2 = left, 3 = up

# Square arena 1.5m x 1.5m, or 1050 x 1050
class Arena:
    def __init__(self, canvas):
        self.x1 = ARENA_X_START
        self.y1 = ARENA_Y_START # need at least 5 space to show top boundary
        self.x2 = ARENA_X_END
        self.y2 = ARENA_Y_END
        self.draw(canvas)
    
    def draw(self, canvas):
        x = canvas.create_rectangle(self.x1, self.y1, self.x2, self.y2)

class Car:
    # car starts at the top left of the arena facing to the right, maybe about 1-2 cm away from the walls?
    def __init__(self, canvas):
        # coords are for center of the car
        self.x = ARENA_X_START + (2 * 7) + (CAR_HEIGHT / 2)
        self.y = ARENA_Y_START + (2 * 7) + WHEEL_WIDTH + (CAR_WIDTH / 2)
        # x 7 bc everything is multiplied by 7, so 2cm
        # self.x1 = ARENA_X_START + 2 * 7
        # self.y1 = ARENA_Y_START + 2 * 7
        # self.x2 = self.x1 + CAR_HEIGHT
        self.carDirection = 0 # 0 = right, 1 = down, 2 = left, 3 = up
        self.draw(canvas)
    
    def draw(self, canvas):
        if len(car_queue) != 0:
            canvas.delete(car_queue[0])
            car_queue.pop()
        
        # print("Hi" + str(self.carDirection))
        
        if self.carDirection == 0:
            x = canvas.create_rectangle(self.x - CAR_HEIGHT / 2, self.y - CAR_WIDTH / 2, self.x + CAR_HEIGHT / 2, self.y + CAR_WIDTH / 2, outline = "blue")
            car_queue.append(x)
            car_history.append(CarHistoryPoint(self.x, self.y, canvas))
            
            canvas.create_line(car_history[len(car_history) - 2].x, car_history[len(car_history) - 2].y, self.x, self.y, fill = "blue")
            # print(car_history[len(car_history) - 1].x)
            # print(car_history[len(car_history) - 1].y)
            # print(self.x)
            # print(self.y)
        if self.carDirection == 1:
            x = canvas.create_rectangle(self.x - CAR_WIDTH / 2, self.y - CAR_HEIGHT / 2, self.x + CAR_WIDTH / 2, self.y + CAR_HEIGHT / 2, outline = "blue")
            car_queue.append(x)
            car_history.append(CarHistoryPoint(self.x, self.y, canvas))
            
            canvas.create_line(car_history[len(car_history) - 2].x, car_history[len(car_history) - 2].y, self.x, self.y, fill = "blue")
    
    def changePos(self, canvas):
        # print("Ho" + str(self.carDirection))
        # if car turns, change how it maps?
        if self.carDirection == 0:
            frontDistanceMode = getFrontDistanceMode()
            # self.x = ARENA_SIDE_LENGTH - getFrontDistanceMode()
            print("Front Distance: " + str(frontDistanceMode))

            try:
                self.x = ARENA_SIDE_LENGTH - (frontDistanceMode * 7)
            except Exception:
                pass
            self.y = ARENA_Y_START + (2 * 7) + WHEEL_WIDTH + (CAR_WIDTH / 2)
            self.draw(canvas)
        
        if self.carDirection == 1:
            frontDistanceMode = getFrontDistanceMode()
            print("Front Distance: " + str(frontDistanceMode))
            try:
                while frontDistanceMode < 5:
                    frontDistanceMode = getFrontDistanceMode()
                self.y = ARENA_SIDE_LENGTH - (frontDistanceMode * 7)
            except Exception:
                pass
            self.draw(canvas)
            # self.x should stay what it is from when the car was moving to the right?

    def startMoving():
        # w: start moving
        SerialPort.write(bytes('w','utf-8'))
    
    def turnRightUntilAligned():
        # d: turn right in place
        SerialPort.write(bytes('d','utf-8'))

class CarHistoryPoint:
    def __init__(self, x, y, canvas):
        self.x = x
        self.y = y
        self.draw(canvas)
    
    def draw(self, canvas):
        size = 3
        x = canvas.create_oval(self.x - size, self.y - size, self.x + size, self.y + size, fill="blue")

class Point:
    def __init__(self, x, y, canvas):
        self.x = x
        self.y = y
        self.draw(canvas)
    
    def draw(self, canvas):
        size = 1
        x = canvas.create_oval(self.x - size, self.y - size, self.x + size, self.y + size, fill="black")

class ObjectSquare:
    pass
    # get 4 side lengths and average out?
    # how to get side lengths: check distances between points and as long as there's a point above or below that's in that threshold, move to that point and keep going in that direction and do the same thing again until you reach the end, or the last point of the side

class ObjectRectangle:
    pass
    # get average distance between two sides and make that the side length for both sides, so based on all the data

def test(canvas):
    points_list.append(Point(100, 100, canvas))
    points_list.append(Point(100, 120, canvas))
    points_list.append(Point(100, 140, canvas))
    points_list.append(Point(100, 160, canvas))
    points_list.append(Point(120, 160, canvas))
    points_list.append(Point(140, 160, canvas))
    points_list.append(Point(160, 160, canvas))
    points_list.append(Point(160, 140, canvas))
    points_list.append(Point(160, 120, canvas))
    points_list.append(Point(160, 100, canvas))
    points_list.append(Point(140, 100, canvas))
    points_list.append(Point(120, 100, canvas))

    topleft = points_list[0]
    # for point in points_list:
        
        
        # set first point as topleft point
        # if there's a point above it (smaller y) and along about the same line (give or take 5u on x axis) that is at most 30u away, it is still part of this mapped shape so make that point the topleft point
        # if there's a point to the left of it (smaller x) and along about the same line (give or take 5u on y axis) that is at most 30u away, it is still part of this mapped shape so make that point the topleft point
        # keep going through this for loop until the topleft and topright points don't change
        #after drawing out that obstacle, pop out all the points used for it. Then you can do the for loop again for the other obstacles

def signal_handler(signal, frame):
    print("closing program")
    SerialPort.close()
    sys.exit(0)

def getFrontDistanceMode():
    front_distances = []
    for i in range(20):
        front_distances.append(getFrontDistance())
    
    try:
        return float(statistics.mode(front_distances))
    except Exception:
        return None  

def getFrontDistance():
	# f: front distance
	SerialPort.write(bytes('f','utf-8'))
	IncomingData = SerialPort.readline()
	if(IncomingData):
		decodedData = (IncomingData).decode('utf-8')
		return decodedData

def getRightDistance():
	# r: right distance
	SerialPort.write(bytes('r','utf-8'))
	IncomingData = SerialPort.readline()
	if(IncomingData):
		decodedData = (IncomingData).decode('utf-8')
		return decodedData

# def getTopLeftPoints(canvas):
#     topLeftPoints = []

def update(car, canvas, window):
    
    # global carDirection
    
    # print(getFrontDistanceMode())
    if getFrontDistanceMode() < 5 and car.carDirection != 3:
        # print(car.x)
        # print(ARENA_SIDE_LENGTH - car.x)
        if ARENA_SIDE_LENGTH - car.x < CAR_HEIGHT / 2:
            car.carDirection = 1
        #TODO: check if works
        elif ARENA_SIDE_LENGTH - car.y < CAR_HEIGHT / 2:
            car.carDirection = 2
        #TODO: check if works
        elif car.x < CAR_HEIGHT / 2:
            car.carDirection = 3
        
        car.turnRightUntilAligned()
    
    print(car.carDirection)

    car.changePos(canvas)
    
    # frontDistanceMode = getFrontDistanceMode()
    # print(frontDistanceMode)

    window.after(100, update, car, canvas, window)

def main():
    window = tk.Tk()
    window.title("Map")

    canvas = tk.Canvas(window, width=WIDTH, height=HEIGHT, bg="white")
    canvas.pack()

    # point = Point(100, 100, canvas)
    arena = Arena(canvas)

    car = Car(canvas)

    test(canvas)

    input = input('> ')

    if input == "start":
        car.startMoving();

    window.after(100, update, car, canvas, window)

    window.mainloop()

main()

# Left and topmost point of all the points will be x1 and y1 of rectangle. And the opposite for the opposite corner. Draw the shape on top of those plotted points

# once the front distance reaches < 5, turn

# TODO: must also track car coords and update it as it moves. And take into account the car dimensions so you know how far the obstacles are from the sensors

# def test():
#     point = Point(100, 100, canvas)