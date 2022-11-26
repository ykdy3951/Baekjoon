for _ in range(int(input())):
    n,k=map(int,input().split())
    s=input();r=0
    for i in range(n//2):
        if s[i] != s[n-1-i]:
            r+=1
    print('Case #%d:'%(_+1), abs(k-r))