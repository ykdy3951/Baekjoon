l=[]
for i in range(int(input())):
    a,b=map(int,input().split())
    l.append([b,a])
l.sort()
print(l[0][1],l[0][0])