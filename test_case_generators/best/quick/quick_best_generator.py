# random vector generator

from random import randint

a = ""

for i in range(0,10):
    a = a + str(100) + ", "  + str(randint(0,1000))
    for j in range(0,99):
        a = a + ", " + str(randint(0,1000))
    a = a + ";\n"

print a
