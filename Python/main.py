import requests
import json
import math
import serial

latdest = 0.000
londest = 0.000

mylat = 0.000
mylon = 0.000
apiKey = "08f0d0a6d3502d07a0e9854bd0c35fe2" #Inserisci la tua api key

myCity = input("Digita la citta' da cercare: ")
req = requests.get("http://api.openweathermap.org/geo/1.0/direct?q="+ myCity +"&appid=" + apiKey)
commits = json.loads(req.text)
londest = commits[0]["lon"]
latdest = commits[0]["lat"]

finallat = latdest - mylat
finallon = londest - mylon

angle = math.atan2(finallat,finallon) * 180 / math.pi

