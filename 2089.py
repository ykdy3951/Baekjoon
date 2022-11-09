n=int(input())

s=''
while n:
    if n % -2:
        n-=1
        n//=-2
        s+='1'
    else:
        n//=-2
        s+='0'
print(s[::-1] if s else '0')