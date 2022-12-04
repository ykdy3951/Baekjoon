for i in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    a=[0]*5001
    for j in range(n):
        for k in range(l[j*2], l[j*2+1]+1):
            a[k]+=1
    print('Case #%d:' %(i+1), end=' ')
    for j in range(int(input())):
        print(a[int(input())],end=' ')
    print()
    input()