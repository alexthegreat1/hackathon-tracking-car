import tkinter as tk

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

# from wheel to wheel, in cm
CAR_WIDTH = 25
CAR_HEIGHT = 24

points_list = []
car_queue = []

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

# class Car:
#     # car starts at the top left of the arena facing to the right, maybe about 1-2 cm away from the walls?
#     def __init__(self, canvas):
#         # coords are for center of the car
#         self.x = ARENA_X_START + (2 * 7) + 
#         # x 7 bc everything is multiplied by 7, so 2cm
#         # self.x1 = ARENA_X_START + 2 * 7
#         # self.y1 = ARENA_Y_START + 2 * 7
#         # self.x2 = self.x1 + CAR_HEIGHT
#         self.carDirection = 0 # 0 = right, 1 = down, 2 = left, 3 = up
#         self.draw(canvas)
    
#     def draw(self, canvas):
#         if len(car_queue) != 0:
#             canvas.delete(car_queue[0])
#             car_queue.pop()
        
#         if self.carDirection == 0:


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

def getTopLeftPoints(canvas):
    topLeftPoints = []

def main():
    window = tk.Tk()
    window.title("Map")

    canvas = tk.Canvas(window, width=WIDTH, height=HEIGHT, bg="white")
    canvas.pack()

    # point = Point(100, 100, canvas)
    arena = Arena(canvas)

    test(canvas)

    window.mainloop()

main()

# Left and topmost point of all the points will be x1 and y1 of rectangle. And the opposite for the opposite corner. Draw the shape on top of those plotted points

# TODO: must also track car coords and update it as it moves. And take into account the car dimensions so you know how far the obstacles are from the sensors

# def test():
#     point = Point(100, 100, canvas)