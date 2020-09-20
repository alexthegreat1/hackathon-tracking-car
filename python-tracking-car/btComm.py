import serial
import time
import sys
import signal

def signal_handler(signal, frame):
    print("closing program")
    SerialPort.close()
    sys.exit(0)

COM="/dev/cu.HC-05-DevB"
BAUD=9600
SerialPort = serial.Serial(COM,BAUD,timeout=1)

while (1):
    try:
        OutgoingData=input('> ')
        SerialPort.write(bytes(OutgoingData,'utf-8'))
    
    except KeyboardInterrupt:
        print("Closing and exiting the program")
        SerialPort.close()
        sys.exit(0)
    
    IncomingData=SerialPort.readline()
    
    if(IncomingData):
        print((IncomingData).decode('utf-8'))
    
    time.sleep(0.01)