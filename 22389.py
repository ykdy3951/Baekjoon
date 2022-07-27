while(True):
    a,b,c=map(int,input().split())
    if [a,b,c]==[0,0,0]:
        break
    x=0
    l=[]
    for _ in range(a):
        l.append(int(input()))
    if a % 2 == 0:
        a+=1
        l.append(1)
    for i in range(b,c+1):
        for j in range(a):
            if i % l[j] == 0 and j % 2 == 0:
                x+=1
                break
            elif i % l[j] == 0:
                break
    print(x)