for i in range(int(input())):
    l=[]
    for j in range(int(input())):
        x,y=map(int,input().split())
        l.append([x,y])
    l.sort()
    s=0
    for a in range(len(l)-1):
        for b in range(a+1,len(l)):
            if l[a][1] > l[b][1]:
                s+=1
    print('Case #%d: %d' %(i+1,s))
