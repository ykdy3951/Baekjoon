n=float(input());s=0
for _ in range(int(input())):
    a,b=map(float,input().split())
    s+=n*a*b
print(s)