l=[]
n=int(input())
a,b,c,d=map(int,input().split())
for i in range(n):
    t1,t2=a,b
    s=0;x,y=0,0
    for j in range(int(input())):
        x,y=map(int,input().split())
        s+=abs(t1-x)+abs(t2-y)
        t1,t2=x,y
    s+=abs(t1-c)+abs(t2-d)
    l.append([s,i+1])
print(sorted(l)[0][1])