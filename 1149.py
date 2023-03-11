import sys
input=sys.stdin.readline
t=int(input())
l=[[0]*3 for _ in range(2)]
for i in range(t):
    l[i%2]=list(map(int,input().split()))
    l[i%2][0]+=min(l[(i+1)%2][1],l[(i+1)%2][2])
    l[i%2][1]+=min(l[(i+1)%2][0],l[(i+1)%2][2])
    l[i%2][2]+=min(l[(i+1)%2][1],l[(i+1)%2][0])
print(min(l[(t-1)%2]))