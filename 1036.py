l=[0]*36
for i in range(int(input())):
    s=input()[::-1]
    k=1
    for i in range(len(s)):
        if s[i] >= '0' and s[i] <= '9':
            l[int(s[i])]+=k
        else:
            l[ord(s[i])-65+10]+=k
        k*=36
a=0
t=[[0,i] for i in range(36)]
for i in range(36):
    t[i][0]=l[i]*(35-i)
t.sort()
m=int(input())
for i in range(36-m):
    a+=l[t[i][1]]*t[i][1]
for i in range(36-m, 36):
    a+=l[t[i][1]]*35
if a==0:
    print(0)
else:
    s=''     
    while a:
        a,y=divmod(a,36)
        if y < 10:
            s+=str(y)
        else:
            s+=chr(55+y)
    print(s[::-1])