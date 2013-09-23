# min heap generator
from random import randint


def heapify(a, count):
    end = 1
    while end < count:
        sift_up(a,0,end)
        end = end + 1

def sift_up(a, start, end):
    child = end
    while child > start:
        parent = (child-1)/2
        if a[parent] >= a[child]:
            aux = a[parent]
            a[parent] = a[child]
            a[child] = aux
            child = parent
        else:
            return

l = []
for i in range(0,50):
    a = []
    for j in range(0,100):
        a.append(randint(0,1000))
    heapify(a,100)
    l.append(a)

s = ""
for i in l:
    s = s + str(i[0])
    for j in i[1:]:
        s = s + ", " + str(j)
    s = s + ";\n"
s = s + "\n"

print s








