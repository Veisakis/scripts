import string
import secrets

sectors = int(input('Sectors: '))
length = int(input('Length of sector: '))

passwords = []
block = string.ascii_letters + string.digits

character_type = input('Letters (l), Letters and Digits (ld), Digits (d), Letters,Digits and special characters (ldc): ')

if character_type == 'l':
    block = string.ascii_letters

elif character_type == 'ld':
    block = string.ascii_letters + string.digits 

elif character_type == 'd':
    block = string.digits 

elif character_type == 'ldc':
    block = string.ascii_letters + string.digits + '!~#$^&*-+='

for _ in range(sectors):
    password = ''.join([secrets.choice(block) for _  in range(length)])
    passwords.append(password)

print('-'.join(passwords))
