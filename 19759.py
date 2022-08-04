n=int(input())
a=100
for i in range(n):
    s=str(a)
    m=25
    l=s[::-1]
    for i in range(len(l)):
        if l[i] != '0':
            m=min(i,m)
            break
    if m*2 < len(s):
        c=len(s)//2+len(s)%2
        s=str(int(s[:len(s)-c])+1)+'0'*c
    a=int(s)
    print(a)
    a*=2