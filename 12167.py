for _ in range(int(input())):
    t,s=input().split();a=int(s[0])
    r=0
    for i in range(1,int(t)+1):
        if i > a:
            r+=i-a
            a=i
        a+=int(s[i])
    print('Case #%d:'%(_+1),r)