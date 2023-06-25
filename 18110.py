import sys
i=sys.stdin.readline
def r(n):
    if n-int(n) >= 0.5:
        return int(n) + 1
    return int(n)

n = int(i())
if not n:
    print(0)
    exit();

x = [int(i()) for _ in range(n)]
x.sort()
e=r(n*0.15)

if e!=0:
    x=x[e:-e]
a=n-2*e
y=sum(x)
print(r(y/a))