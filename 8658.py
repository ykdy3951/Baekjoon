n=int(input());a,b=0,0
for i in range(2,n):
    if n % i:
        a=i
        break
for i in range(n-1, 1, -1):
    if n % i:
        b=i
        break
print(a,b)