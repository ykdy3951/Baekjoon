n=int(input())
p=0
while(True):
    if n % 2:
        break
    n//=2
    p+=1
print(n,p)