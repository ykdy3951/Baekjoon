l=list(map(int,input().split()))
for i in l:
    for j in range(i-1,0,-1):
        print(' '*(i-1-j)+'*'+' '*(2*j-1)+'*')
    print(' '*(i-1)+'*')