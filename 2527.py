for _ in range(4):
    l=list(map(int,input().split()))
    x=l[:4];y=l[4:]
    if x[0] > y[2] or x[2] < y[0] or x[1] > y[3] or x[3] < y[1]:
        print('d')
    elif (x[0]==y[2] and x[1]==y[3]) or (x[2]==y[0] and x[1]==y[3]) or (x[0]==y[2] and x[3]==y[1]) or (x[2]==y[0] and x[3]==y[1]):
        print('c')
    elif x[0]==y[2] or x[2]==y[0] or x[1]==y[3] or x[3]==y[1]:
        print('b')
    else:
        print('a')