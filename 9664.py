a,b=map(int,open(0))
n=b+b//(a-1)
if b % (a-1):
    print(n,n)
else:
    print(n-1,n)