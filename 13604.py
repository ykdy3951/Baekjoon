j,r=map(int,input().split())
l=list(map(int,input().split()))
s=[0]*j
for i in range(r):
    for k in range(j):
        s[k]+=l[j*i+k]
t=[]
for i in range(j):
    if s[i] == max(s):
        t.append(i+1)
print(t[-1])