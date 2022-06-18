for k in range(int(input())):
    n,x,y,i,j=map(int,input().split());s='NO'
    if (abs(x-i) == 2 and abs(y-j) == 1) or (abs(x-i) == 1 and abs(y-j) == 2):
        s='YES'
    print('Case %d:' %(k+1), s)