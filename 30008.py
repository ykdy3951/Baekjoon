n,k=map(int,input().split())
l=list(map(lambda x:int(x)*100//n,input().split()))
for i in l:
    a=1
    if i>4:
        a+=1
    if i>11:
        a+=1
    if i>23:
        a+=1
    if i>40:
        a+=1
    if i>60:
        a+=1
    if i>77:
        a+=1
    if i>89:
        a+=1
    if i>96:
        a+=1
    print(a,end=' ')