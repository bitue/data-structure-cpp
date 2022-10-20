import json
print("u")
from time import sleep
import requests

api_url = "https://api.openweathermap.org/data/2.5/weather?q=AREA&appid=4b5f5c378962441c1c0063e2bb400c5c&fbclid=IwAR0buA4zsBQIUE1JHUWCQvr5gXYiBFK-r7HCPlwSpe1VFpS9tDZ3YgtCP-s"
print("u")
while 1:
    res = requests.get(api_url)
    content = res.content.decode('UTF-8')
    dict_data = json.loads(content)
    print(dict_data)
    sleep(1800)