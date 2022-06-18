a,b=map(int,input().split());s=0;i=1;t=0
while(True):
    t=a+i
    s+=(1 if i==1 else abs(t-(a+i//-2)))
    if (a > b and t <= b) or (a < b and t >= b):
        break
    i*=-2
if (a > b and t <= b) or (a < b and t >= b):
    s-=abs(t-b)
print(abs(s))