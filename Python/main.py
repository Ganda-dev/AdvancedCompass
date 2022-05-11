import requests
import json
import math
import serial

ser = serial.Serial("COM4", 115200)
latdest = 0.0000
londest = 0.0000

mylat = 45.556564
mylon = 10.217026
#mylon = ser.read_until(';')
#mylat = ser.read_until('/')


apiKey = "08f0d0a6d3502d07a0e9854bd0c35fe2" #Inserisci la tua api key

myCity = input("Digita la citta' da cercare: ")
req = requests.get("http://api.openweathermap.org/geo/1.0/direct?q="+ myCity +"&appid=" + apiKey)
commits = json.loads(req.text)
londest = commits[0]["lon"]
latdest = commits[0]["lat"]

finallat = latdest - mylat
finallon = londest - mylon

angle = math.ceil(math.atan2(finallat,finallon) * 180 / math.pi)
finalAngle = 0
if(angle < 0):
    finalAngle = 360 + angle
else:
    finalAngle = angle

print(finalAngle)

ser.write(str(finalAngle).encode())
ser.write('/'.encode())