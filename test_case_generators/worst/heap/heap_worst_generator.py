# max heap generator
from random import randint

def heapify(a, count):
    start = (count-2)/2
    while start >= 0:
        sift_down(a,start,count-1)
        start = start - 1

def sift_down(a, start, end):
    root = start
    while root*2+1 <= end:
        child = root*2+1
        swap = root
        if a[swap] < a[child]:
            swap = child
        if (child+1 <= end) and (a[swap] < a[child+1]):
            swap = child + 1
        if swap != root:
            aux = a[root]
            a[root] = a[swap]
            a[swap] = aux
            root = swap
        else:
            return

l = []
for i in range(0,10):
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
