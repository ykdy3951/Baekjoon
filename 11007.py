for _ in range(int(input())):
    l='abcdefghijklmnopqrstuvwxyz'
    input()
    for i in list(map(int,input().split())):
        print(l[i],end='')
        l=l[i]+l[:i]+l[i+1:]
    print()