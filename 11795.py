i,j,k=0,0,0
for _ in range(int(input())):
    a,b,c=map(int,input().split())
    i+=a;j+=b;k+=c
    m=min(i,j,k)
    if m >= 30:
        print(m)
        i-=m;j-=m;k-=m
    else:
        print('NO')
