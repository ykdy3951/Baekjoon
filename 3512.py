n,m=map(int,input().split())
x,y,z=0,0,0
for i in range(n):
    a,b=input().split()
    x+=int(a)
    if b=='bedroom':
        y+=int(a)
    z+=float(a)
    if b == 'balcony':
        z-=int(a)/2
print(x)
print(y)
print(z*m)