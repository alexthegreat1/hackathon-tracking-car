# import mapGUI
# import btComm
import serial
import time
import sys
import signal

def signal_handler(signal, frame):
    print("closing program")
    SerialPort.close()
    sys.exit(0)

COM = "/dev/cu.HC-05-DevB"
BAUD = 9600
SerialPort = serial.Serial(COM,BAUD,timeout=1)

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

def main():
	# while (1):
	# 	IncomingData = SerialPort.readline()

	# 	if(IncomingData):
	# 		# print((IncomingData).decode('utf-8'))
	# 		decodedData = (IncomingData).decode('utf-8')
	print(getFrontDistance())
	print(getRightDistance())

main()