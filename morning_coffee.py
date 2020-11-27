# -*- coding: utf-8 -*-

import requests
import bs4
from bs4 import BeautifulSoup
import time

# Ειδήσεις
r = requests.get("https://www.kathimerini.gr/epikairothta/")
soup = BeautifulSoup(r.text, "html.parser")


for new in soup.find_all("div", class_="design_one_title_big"):
    print(new.text.strip())
    print(new.a.get('href'))
    print("\n")
    time.sleep(7)

# Καιρός
days = ["ΔΕΥΤΕΡΑ", "ΤΡΙΤΗ", "ΤΕΤΑΡΤΗ", "ΠΕΜΠΤΗ", "ΠΑΡΑΣΚΕΥΗ", "ΣΑΒΒΑΤΟ", "ΚΥΡΙΑΚΗ"]
weather = {}

r = requests.get("https://kairos123.gr/a/21/kriti_xania")
soup = BeautifulSoup(r.text, "html.parser")

# Εύρεση σημερινής μέρας
today = soup.find(class_="span_7 current").find("h3")
key_today = today.text.split()
today_key = key_today[0]
# Εύρεση σημερινής μέρας

# Εύρεση θέσης σημερινής μέρας στον πίνακα days
for i in range(0, 6):
    if today_key == days[i]:
        day_index = i
# Εύρεση θέσης σημερινής μέρας στον πίνακα days

# Πρόγνωση ημερών
for forecast in soup.find_all(class_="span_7"):
    list = forecast.text.split()
    weather[list[0]] = list[1]
# Πρόγνωση ημερών

# Τελική εκτύπωση
for i in range(day_index, day_index + 5):
    print(days[i] + " : " + weather[days[i]])
    time.sleep(1)
# Τελική εκτύπωση


