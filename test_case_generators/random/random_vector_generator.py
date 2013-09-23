# random vector generator

from random import randint

a = ""

for i in range(1,51):
    a = a + str(randint(0,1000))
    for j in range(0,(20*i)-1):
        a = a + ", " + str(randint(0,1000))
    a = a + ";\n"
a = a + "\n"

print a
