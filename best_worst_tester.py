import os

sorts = ["bubble", "heap", "insertion", "merge", "quick"]

for i in sorts:
    print i + " best"
    os.system("./" + i + "/" + i +"<" + i + "/" + i.capitalize() + "_M.txt>" + i + "/best_results")
    print i + " worst"
    os.system("./" + i + "/" + i +"<" + i + "/" + i.capitalize() + "_P.txt>" + i + "/worst_results")
