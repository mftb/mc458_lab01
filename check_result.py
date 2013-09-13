#!/usr/bin/env python

f = open("out.csv","r")
a = f.readlines()
f.close()

a = a[2:]

sorted_list = []
unsorted_list = []

for i in a:
    x = i.split(',')
    unsorted_list.append(x[0])
    sorted_list.append(x[1])

y = 0

new_sorted = [int(i) for i in sorted_list]
new_unsorted = [int(i) for i in unsorted_list]
new_unsorted.sort()

for i in range(0,len(a)):
    y = y + new_sorted[i] - new_unsorted[i]
    
if y == 0:
    print "TEST PASSED"
