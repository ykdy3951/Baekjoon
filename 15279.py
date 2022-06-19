for _ in range(int(input())):
    b,p=map(float,input().split())
    i=60/(p/(b-1));j=60*b/p;k=2*j-i
    print('%.4f %.4f %.4f' %(i,j,k))