while(True):
    a,b,c=map(int,input().split())
    if [a,b,c]==[0,0,0]:
        break

    if a//2+a%2 <= c:
        print(-1)
    else:
        print(max(a//2+1-b,0))