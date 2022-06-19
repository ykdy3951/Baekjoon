for _ in range(int(input())):
    k,x,y=map(int,input().split())
    if x > y:
        x,y=y,x
    print(x+2-y if x+2 > k else k-y)