l=[]
for i in range(int(input())):
    x,y=map(int,input().split())
    l.append([x,y])
D=[]
for i in range(len(l)):
    t=[]
    for j in range(len(l)):
        t.append((l[i][0]-l[j][0])**2+(l[i][1]-l[j][1])**2)
    D.append(t)
for i in range(int(input())):
    a,d=map(int,input().split())
    d*=d
    c=0
    for j in D[a-1]:
        if j <= d:
            c+=1
    print(c-1)