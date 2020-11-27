import string
import random

repository = list(string.ascii_letters)
length = int(input("How many digits: "))
pswd = []

for i in range(length):
    c = random.randint(0,len(repo)-1)
    d = repository[c]
    pswd.append(d)

password = "".join(pswd)
print(password)
            
