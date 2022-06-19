while(True):
    r,w,c,a=map(int,input().split())
    if [r,w,c,a]==[0,0,0,0]:
        break
    n=0
    while(True):
        if r/w >= c:
            print(n)
            break
        r+=a
        n+=1