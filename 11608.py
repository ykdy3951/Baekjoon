d={}
for i in input():
    if i not in d:
        d[i]=0
    d[i]+=1
print(sum(sorted(d.values())[:-2]) if len(d.values()) > 2 else 0)