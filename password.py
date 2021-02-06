import string
import secrets

sectors = int(input('Sectors: '))
length = int(input('Length of sector: '))

passwords = []
alphabet = string.ascii_letters + string.digits

for _ in range(sectors):
    password = ''.join([secrets.choice(alphabet) for _  in range(length)])
    passwords.append(password)

print('-'.join(passwords))
