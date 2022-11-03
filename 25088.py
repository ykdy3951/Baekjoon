for i in range(int(input())):
    x,y=map(int,input().split())
    print('Case #%d:' %(i+1))
    a='..+'+'-+'*(y-1)
    b='..|'+'.|'*(y-1)
    c='+'+'-+'*y
    d='|'+'.|'*y
    print(a)
    print(b)
    print(c)
    for j in range(x-1):
        print(d)
        print(c)