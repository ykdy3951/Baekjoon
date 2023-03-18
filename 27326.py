n=int(input())
l=[0]*n

for i in list(map(int,input().split())):
    l[i-1]=1-l[i-1]

for i in range(n):
    if l[i]:
        print(i+1)
        break