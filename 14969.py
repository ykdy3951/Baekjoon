while True:
    a,b=map(int,input().split())
    if [a,b]==[0,0]:
        break
    l=list(map(int,input().split()))
    s=0
    for i in range(a-1):
        for j in range(i+1,a):
            if l[i]+l[j]>b:
                continue
            s=max(s,l[i]+l[j])
    print(s if s else 'NONE')