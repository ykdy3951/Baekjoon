l=list(map(int,input().split()));l.sort()
if l[1] == 0:
    print(sum(l))
else: 
    print(l[0]+l[1]*l[2])