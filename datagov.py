import requests
import os
import datetime

now_obj = datetime.datetime.now()
date = now_obj.strftime('%Y-%m-%d')

date = '2020-12-05' 

url = 'https://data.gov.gr/api/v1/query/admie_dailyenergybalanceanalysis?date_from='+date+'&date_to='+date
headers = {'Authorization':'Token ' + os.environ['GEO_API']}

r = requests.get(url, headers=headers)

print(r.json())
