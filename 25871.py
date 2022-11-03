l=list(input().split())[1:]
n=int(input())
i=0
while True:
    a,b=n-i,n+i
    if a >= 0:
        a=str(a)
        f=True
        for j in a:
            if j in l:
                f=False
                break
        if f:
            print(i)
            break        
    if b <= 999:
        b=str(b)
        f=True
        for j in b:
            if j in l:
                f=False
                break
        if f:
            print(i)
            break
    i+=1