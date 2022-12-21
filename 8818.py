for _ in range(int(input())):
    n=int(input())
    k=1;c=0
    while k < n:
        k *= 2
    if k != n:
        while n:
            k//=2
            if n >= k:
                n-=k
            c+=1
    print(c)