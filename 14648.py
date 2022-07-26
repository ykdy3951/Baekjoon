n,q=map(int,input().split())
l=list(map(int,input().split()))
for i in range(q):
    a=list(map(int,input().split()))
    if a[0] == 1:
        print(sum(l[a[1]-1:a[2]]))
        l[a[1]-1],l[a[2]-1]=l[a[2]-1],l[a[1]-1]
    else:
        print(sum(l[a[1]-1:a[2]])-sum(l[a[3]-1:a[4]]))