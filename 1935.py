n=int(input())
l=input()
v=[]
for i in range(n):
    v.append(int(input()))
s=[]
for i in l:
    if i in '*+/-':
        b=s.pop();a=s.pop()
        if type(a) == str:
            a=v[ord(a)-65]
        if type(b) == str:
            b=v[ord(b)-65]
        s.append(eval(str(a)+i+str(b)))
    else:
        s.append(i)
print('%.2f' %s[0])