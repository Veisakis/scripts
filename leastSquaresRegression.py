import pandas as pd
import numpy as np

def newTable(dim):
    table=[]
    for i in range(dim):
        table.append(['.', '.', '.', '.'])
    return table

def a(N,sumx,sumy,sumxy,sumx2):
    return ((N*sumxy)-(sumx*sumy))/((N*sumx2)-((sumx)**2)) 

def b(N,sumx,sumy,sumxy,sumx2):
    return ((sumx2*sumy)-(sumxy*sumx))/((N*sumx2)-(sumx**2))


rows = input('How many rows?: ')
table = newTable(int(rows))

for o in range(len(table)):
    print()
    print(o+1)
    x = float(input('Give x: '))
    y = float(input('Give y: '))
    table[o][0] = x
    table[o][1] = y

sumx = 0
sumy = 0
sumxy = 0
sumx2 = 0
N = len(table)

xy = lambda x,y : x*y
x2 = lambda x : x**2

for k in range(len(table)):
    table[k][2] = xy(table[k][0],table[k][1])
    table[k][3] = x2(table[k][0])

for z in range(1,len(table)):
    sumx = sumx + table[z][0]
    sumy = sumy + table[z][1]
    sumxy = sumxy + table[z][2]
    sumx2 = sumx2 + table[z][3]
     
table.append([sumx, sumy, sumxy, sumx2])
a = a(N,sumx,sumy,sumxy,sumx2)
b = b(N,sumx,sumy,sumxy,sumx2)

for w in range(len(table)):
    for m in range(4):
        table[w][m] = str(round(table[w][m],2))

data = {
        'x':[],
        'y':[],
        'xy':[],
        'x2':[]
        }

for f in range(len(table)):
    data['x'].append(table[f][0])
    data['y'].append(table[f][1])
    data['xy'].append(table[f][2])
    data['x2'].append(table[f][3])

df = pd.DataFrame(data)

print()
print()
print(df)
print()
print('y = ' + str(round(a,2)) + 'x + ' + str(round(b,2)))
