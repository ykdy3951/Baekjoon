for i in range(int(input())):
    print('Test case #%d:' %(i+1))
    d={}
    for _ in range(int(input())):
        a,b=input().split()
        d[a]=b
    for j in range(int(input())):
        s=input()
        t=s
        for x in d.keys():
            t=t.replace(x, d[x])
        print(s, ['NO','YES'][t==t[::-1]])
    print()