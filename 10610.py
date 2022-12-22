n=sorted(list(input()));c=n.count('0');s=0
if c:
    for i in n:
        s+=int(i)
if c != 0 and s % 3 == 0:
    print(''.join(n[-1:c-1:-1])+'0'*c)
else:
    print(-1)