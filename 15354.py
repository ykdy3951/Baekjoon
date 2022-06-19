l=list(open(0));n=int(l[0]);l=l[1:]
t=l[0];s=1
for i in range(1,n):
    if l[i] == t:
        continue
    else:
        t=l[i]
        s+=1
print(s+1)