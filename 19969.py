a,b,c=map(int,input().split())
x,y,z=map(int,input().split())
s=0
t=min(a,x)
a-=t
x-=t
s+=t
t=min(b,y)
b-=t
y-=t
s+=t
if a > 0 and z > 0:
    t=min(a,z)
    s+=t
    a-=t
    z-=t
if b > 0 and z > 0:
    t=min(b,z)
    s+=t
    b-=t
    z-=t
if x > 0 and c > 0:
    t=min(x,c)
    s+=t
    x-=t
    c-=t
if y > 0 and c > 0:
    t=min(y,c)
    s+=t
    y-=t
    c-=t
print(s+min(c,z))