import psutil
import serial
import struct
import time

arduinoData = serial.Serial('com3',9600,  timeout=.1)
time.sleep(1)

battery = psutil.sensors_battery()
plugged = battery.power_plugged
percent: str = str(battery.percent)
if plugged==False: plugged="Not Plugged In"
else: plugged="Plugged In"
print(percent+'% | '+plugged)

arduinoData.write(int(percent))
