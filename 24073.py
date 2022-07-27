n=int(input())
l=input()
if l.count('I') > 1 and l.count('O'):
    a=l.index('I');b=n-l[::-1].index('I')-1
    s='No'
    for i in range(a+1,b):
        if l[i] == 'O':
            s='Yes'
            break
    print(s)
else:
    print('No')