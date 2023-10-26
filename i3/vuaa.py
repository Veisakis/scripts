#!/usr/bin/python3

import requests
from bs4 import BeautifulSoup

qty = 15
url = "https://www.morningstarfunds.ie/ie/etf/snapshot/snapshot.aspx?id=0P0001J2VU"

r = requests.get(url)
soup = BeautifulSoup(r.text, 'lxml')

price_raw = soup.find('div', class_='layout_content').find('td', class_='line text').get_text()
price = float(price_raw.split()[1])

print("{:.2f} €".format(qty * price))

