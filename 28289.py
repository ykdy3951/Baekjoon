import sys
input=sys.stdin.readline
l=[0,0,0,0]
for i in range(int(input())):
    a,b,c=map(int,input().split())
    if a == 1:
        l[-1]+=1
    else:
        l[max(0,b-2)]+=1
print('\n'.join(map(str,l)))