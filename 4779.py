l=list(map(int,open(0)))
s=[]

def f(n):
    if n == 0:
        print('-',end='')
        return
    f(n-1)
    print(' '*(3**(n-1)),end='')
    f(n-1)

for i in l:
    f(i);print()
