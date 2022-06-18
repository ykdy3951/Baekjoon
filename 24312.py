l=list(map(int,input().split()))
l.sort()
print(min(abs(l[0]+l[3]-l[1]-l[2]), abs(l[0]+l[2]-l[1]-l[3]), abs(l[3]-l[0]-l[1]-l[2])))