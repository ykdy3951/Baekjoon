while(True):
    n=int(input())
    if n == 0:
        break
    x,y=map(int,input().split())
    for _ in range(n):
        i,j=map(int,input().split())

        if i == x or j == y:
            print('divisa')
        elif i > x and j > y:
            print('NE')
        elif i > x and j < y:
            print('SE')
        elif i < x and j < y:
            print('SO')
        else:
            print('NO')