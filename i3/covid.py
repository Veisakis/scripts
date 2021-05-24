#!/usr/bin/env python
import requests
import pandas as pd
from datetime import date, timedelta

obj_1 = date.today() - timedelta(days=1)
date_1 = obj_1.strftime('%Y-%m-%d')

obj_2 = date.today() - timedelta(days=2)
date_2 = obj_2.strftime('%Y-%m-%d')

url = 'https://data.gov.gr/api/v1/query/mdg_emvolio?date_from='+date_2+'&date_to='+date_1
headers = {'Authorization':'Token cae197251734baf5d81483596ac52d81cb41b779'}

r = requests.get(url, headers=headers)

df = pd.DataFrame(r.json())
print(df['totaldistinctpersons'].sum())
