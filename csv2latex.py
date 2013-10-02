f = open("a.csv","r")
a = f.readlines()
f.close()

b = []
for i in a:
    b.append(i.split(','))

print "\\begin{center}"
print "\\begin{table}"
print "\\begin{tabular}{| c | c | c | c | c | c |}"
print "\\hline"
for i in b:
    s = ""
    for j in i:
        if j != i[-1]:
            if "\"" in j:
                s = s + j[1:-1] + " & "
            else:
                s = s + j + " & "
        else:
            if "\"" in j:
                s = s + j[1:-2] + " \\\\ \\hline "
            else:
                s = s + j[:-1] + " \\\\ \\hline "
    print s
print "\\end{tabular}"
print "\\end{table}"
print "\\end{center}"

