l=[]
for i in range(int(input())):
    l.append(input())
m=int(input())
for i in range(m):
    a,b=map(int,input().split())
    for j in range(a-1,b):
        print(l[j])