f = open("a.csv","r")
a = f.readlines()
f.close()

b = []
for i in a:
    i.split(",")
    b.append(i)
print b


#print "\\begin{table}"
#print "\\begin{tabular}{| p{5cm} | p{5cm} | p{5cm} | p{5cm} |}"
#print "\\hline"

