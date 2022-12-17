n=int(input())
print('|'+'-'*(n-2)+'|')
for i in range(1,n-1):
    t=abs(i-n//2)
    x=abs(1-n//2)
    if t == 0:
        print('|'+' '*(x-t)+'*'+' '*(x-t)+'|')
    else:
        print('|'+' '*(x-t)+'*'+' '*(2*t-1)+'*'+' '*(x-t)+'|')
print('|'+'-'*(n-2)+'|')