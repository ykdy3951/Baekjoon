for _ in range(int(input())):
    a=list(map(float,input().split()))
    b=list(map(float,input().split()))
    A,G=0,0
    for i in range(3):
        A+=a[i]*b[(i+1)%3]
        G+=b[i]*a[(i+1)%3]
    if A > G:
        print('ADAM')
    elif A < G:
        print('GOSIA')
    else:
        print('=')
