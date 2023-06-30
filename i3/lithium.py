#!/usr/bin/python

import requests
from bs4 import BeautifulSoup

url = "https://tradingeconomics.com/commodity/lithium"
headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/114.0'}
r = requests.get(url, headers=headers)

soup = BeautifulSoup(r.text, "html.parser")

td = soup.find_all('table', class_="table")
lithium = float(td[1].find_all("tr")[1].find_all("td")[1].get_text())

print("⛏️",lithium)


