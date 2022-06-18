for i in range(int(input())):
    print('Case %d: ' %(i+1), end='')
    l=list(map(int,input().split()))
    print(l[0]-1, end=' ')
    for j in l[1:-1]:
        print(j*l[0],end=' ')
        l[0]-=1
    print()