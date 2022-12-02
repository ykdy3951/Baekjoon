x,n=map(int,input().split());s='1'
t=1
while True:
    t*=x
    s+=str(t)
    if len(s) >= n:
        break
print(s[n-1])