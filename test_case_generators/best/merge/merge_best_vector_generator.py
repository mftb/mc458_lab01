# half sorted vectors, half inverted sorted vectors

v_out = ""

for i in range(0,5):
    v_out = v_out + "100, "
    for j in range(0,100):
        v_out = v_out + str(j*i)
        if j < 99:
            v_out = v_out + ", "
        else:
            v_out = v_out + ";\n"
for i in range(1,6):
    v_out = v_out + "100, "
    for j in range(0,100):
        v_out = v_out + str((100-j)*i)
        if j < 99:
            v_out = v_out + ", "
        else:
            v_out = v_out + ";\n"
            


print v_out


