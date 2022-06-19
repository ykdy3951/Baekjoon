n=int(input())
a=0
while(True):
    if n == 1:
        print(a)
        break
    if n % 2:
        n+=1
    else:
        n//=2
    a+=1
