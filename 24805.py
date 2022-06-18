a,b,c=map(int,input().split())
s=0;i=1
while(True):
    s+=a
    if s >= c:
        print(i)
        break
    i+=1;s-=b