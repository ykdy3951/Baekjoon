for _ in range(int(input())):
    x=input()
    l=[0 for _ in range(len(x)+1)]
    for i in range(len(x)):
        if x[i] == 'B':
            l[i+1]+=1
        l[i+1]+=l[i]
    i,j=map(int,input().split())
    i-=1
    print('Case #%d:', l[len(x)]*(j//len(x)-i//len(x))+l[j%len(x)]-l[i%len(x)])