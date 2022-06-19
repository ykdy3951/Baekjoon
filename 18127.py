a,b=map(int,input().split())
l=[1]
l.append(a)
while(len(l) <= b):
    l.append(l[-1]+(len(l)+1)*(a-2)-(a-3))
print(l[b])