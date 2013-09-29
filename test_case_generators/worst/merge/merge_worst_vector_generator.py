# each vector is a merge of 2 different but sorted vectors

v_out = ""

for i in range(1,11):
    v_out = v_out + "100, "
    for j in range(0,100):
        if j%2 == 0:
            x = j
        else:
            x = (100+i)*j
        v_out = v_out + str(x*i)
        if j < 99:
            v_out = v_out + ", "
        else:
            v_out = v_out + ";\n"

print v_out


