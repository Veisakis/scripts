import string
import random

repository = list(string.ascii_letters)
password_size = int(input("How many digits: "))
password_list = []

for i in range(password_size):
    choose_random = random.randint(0, len(repository)-1)
    random_character = repository[choose_random]
    password_list.append(random_character)

password = "".join(password_list)
print(password)
            
