a,b=map(int,input().split())
l=[list(map(lambda x: 1 if x == '#' else 0, list(input()))) for _ in range(a)]
for i in range(a):
    x=0;t=0
    for j in range(b):
        if l[i][j] == 1:
            x+=1
        else:
            if x > 0:
                print(x,end=' ')
                t+=1
                x=0
    if x > 0:
        print(x, end=' ')
        t += 1
    if t == 0:
        print(0, end='')
    print()
for i in range(b):
    x=0;t=0
    for j in range(a):
        if l[j][i] == 1:
            x+=1
        else:
            if x > 0:
                print(x,end=' ')
                t+=1
                x=0
    if x > 0:
        print(x, end=' ')
        t += 1
    if t == 0:
        print(0, end='')
    print()