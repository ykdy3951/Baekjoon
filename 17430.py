import sys
input=sys.stdin.readline

for i in range(int(input())):
    n=int(input())
    l=sorted(tuple(map(int,input().split())) for _ in range(n))
    b=1;x=n
    for j in range(n-1):
        if l[j][0]!=l[j+1][0]:
            x=j+1
            break
    x_list = [l[j][1] for j in range(x)]
    for j in range(x-1,n):
        if x_list[j%x]!=l[j][1]:
            b=0
            break
    print(['NOT BALANCED','BALANCED'][b])