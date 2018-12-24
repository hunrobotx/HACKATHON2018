import psutil
import serial

#flag=0
battery = psutil.sensors_battery()
plugged = battery.power_plugged
percent = str(battery.percent)
if plugged==False:
    plugged="Not Plugged In"
    #flag=0
else:
    plugged="Plugged In"
    #flag=1
print(percent+'% | '+plugged)

converted_percent = (int(percent) / 100) * 180
converted_percent = round(converted_percent)
converted_percent = str(converted_percent)
print(converted_percent+' Degree | '+plugged)

byte_data = converted_percent.encode()

ser = serial.Serial()
ser.baudrate = 9600
ser.port ='COM5'
ser.open()
ser.write(byte_data)
ser.close()






 
