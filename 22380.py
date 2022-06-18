l=list(open(0))
for i in range(0, len(l)-1, 2):
    n,m=map(int,l[i].split())
    a=list(map(int,l[i+1].split()))
    s=0
    for j in a:
        s+=min(j, m//n)
    print(s)