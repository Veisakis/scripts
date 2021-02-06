from mpl_toolkits.basemap import Basemap
import os
import re
import requests
import matplotlib.pyplot as plt
import numpy as np


pattern = re.compile(r'\d+[.]\d+[.]\d+[.]\d+')

key = os.environ['GEO_API']

# ip_trace = input('IP: ')
# cmd = 'traceroute ' + ip_trace + ' > /Users/Manousos/Desktop/addresses.txt'
cmd = 'traceroute 8.8.8.8 > /Users/Manousos/Desktop/addresses.txt'
os.system(cmd)
filepath = 'addresses.txt'

colors = ['b', 'g', 'r', 'c', 'm', 'y']
y = 0

map = Basemap(projection='mill', lat_0=0, resolution='l')
map.drawcoastlines()
map.fillcontinents(color='coral', lake_color='aqua')


locations = {'latitude': [], 'longitude': []}

with open(filepath) as f:
    lines = f.readlines()

    for line in lines:
        ip = pattern.search(line).group(0)
        url = 'http://api.ipstack.com/' + ip + '?access_key=' + key

        r = requests.get(url)
        GEO = r.json()

        locations['latitude'].append(GEO['latitude'])
        locations['longitude'].append(GEO['longitude'])

for i in range(len(locations['latitude'])):

    if i >= 1:
        lon1 = locations['longitude'][i - 1]
        lat1 = locations['latitude'][i - 1]

        lon2 = locations['longitude'][i]
        lat2 = locations['latitude'][i]

        if (lat1 is not None) and (lon2 is not None) and (lat2 is not None):
            y += 1
            if y == len(colors):
                y = 0

            map.drawgreatcircle(lon1, lat1, lon2, lat2,
                                linewidth=2, color=colors[y])

plt.show()
