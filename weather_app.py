import requests
import json

url = "https://community-open-weather-map.p.rapidapi.com/weather"

#city = input('City name?: ')

headers = {
    'x-rapidapi-key': "c770bf4c79msh7a35f97125713cep1cccabjsnecbb429e5d71",
    'x-rapidapi-host': "community-open-weather-map.p.rapidapi.com"
    }

r = requests.get(url,headers=headers,params={"q":"Athens,gr"})

temp_kelvin = r.json()['main']['temp_min']
temp_celcius = float(temp_kelvin) - 273.15

print(str(round(temp_celcius,1)) + ' oCelcius')
