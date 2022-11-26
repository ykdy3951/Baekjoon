def f(n):
    return int(round(float(n)*100,1))
a,b,c=map(f,input().split())
x=0
for i in range((a//b)+1):
    t=a-b*i
    if t%c==0:
        print(i,t//c)
        x=1
if not x:
    print('none')