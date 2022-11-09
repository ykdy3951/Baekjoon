a,b=map(int,input().split())

s=''
while a:
    a,x=divmod(a,b)
    s+=str(x) if x < 10 else chr(x+55)
print(s[::-1])