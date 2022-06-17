for i in range(int(input())):
    n,k,s=map(int,input().split())
    print('Case #%d: %d' %(i+1,min(n+k,n+2*k-2*s)))