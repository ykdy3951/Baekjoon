import sys
input=sys.stdin.readline
a=[[0]*45 for _ in range(2)];a[0][1]=a[1][1]=1
# a[1][i] : ith OS is door os
# a[0][i] : ith OS is not door os
for i in range(2,40+1):
    a[1][i]=a[0][i-1]
    a[0][i]=a[0][i-1]+a[1][i-1]


for i in range(int(input())):
    n=int(input())
    print('Scenario '+str(i+1)+':')
    print(a[0][n]+a[1][n])
    print()