n=input();l=len(n)
for i in range(1,l):
    if int(n[-i]) >= 5:
        n=int(n)
        n//=(10**i)
        n+=1
        n*=10**i
    else:
        n=int(n)
        n//=(10**i)
        n*=10**i
    n=str(n)
print(n)