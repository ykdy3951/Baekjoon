k,d=map(int,input().split())
s=0;i=0
while(True):
    s+=k
    if s > d:
        break

    k*=2
    i+=1
print(i)