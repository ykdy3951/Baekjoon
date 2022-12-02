def f(i):
    if i >= '0' and i <= '9':
        return ord(i)-ord('0')
    else:
        return ord(i)-65+10
s1=input()
s2=input()
n=len(s1)
n//=2
a,b=[],[]
c=[]
for i in range(n):
    a.append(16*f(s1[2*i])+f(s1[2*i+1]))
for i in range(n+1):
    b.append(16*f(s2[2*i])+f(s2[2*i+1]))
c.append(32^b[0])
for i in range(1,n+1):
    c.append(c[i-1]^a[i-1]^b[i])
for i in range(n+1):
    print('%X%X' %(c[i]//16,c[i]%16),end='')
print()