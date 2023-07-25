n=int(input())
l=[0]+list(map(int,input().split()))
x=int(input())

for i in range(1,n+1):
    if i*x == l[i] or (l[i-1] < (i-1)*x and l[i] > i*x) or (l[i-1] > (i-1)*x and l[i] < i*x):
        print('T')
        exit()
print('F')