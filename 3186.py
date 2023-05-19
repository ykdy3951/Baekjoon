k,l,n=map(int,input().split())
s=input()
a,c=0,0;f=False
g=1
for i in range(n):
    if s[i] == '1':
        c=0
        a+=1
        if a >= k:
            f=True
    else:
        a=0
        c+=1
        if f and c >= l:
            print(i+1)
            g=0
            f=False
if f:
    print(n+l)
    g=0
if g:
    print('NIKAD')