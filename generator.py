import string
import random

size = 100000
phone_number_size = 7


def generate_phone_number():
    result = ""
    for i in range(phone_number_size):
        result += str(random.randint(0,9))
    return result


def generate_string():
    result = ''.join([random.choice(string.ascii_letters) for n in range(random.randint(2,16))])
    return result

def generate_age():
    return random.randint(0, 120)

f = open("gen_phonebook.txt", "w")


for i in range(size):
    last_name = generate_string()

    first_name = generate_string()

    phone_number = generate_phone_number()

    age = generate_age()

    f.write("%-21s %-21s %-21s %-21d\n" % (last_name, first_name, phone_number, age))

f.close()
