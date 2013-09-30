import os

sorts = ["bubble", "heap", "insertion", "merge", "quick"]

for i in sorts:
    print i + " random"
    os.system("./" + i + "/" + i +"<" + i + "/" + "Aleatorios.txt>" + i + "/random_results")
