w,n=input().split()
n=int(n)
l=[]
for i in range(n):
    l.append(list(input().split()))
if w in 'DU':
    for i in l[::-1]:
        for j in i:
            if j == '2':
                j='5'
            elif j == '5':
                j='2'
            elif j not in '18':
                j='?'
            print(j,end=' ')
        print()
else:
    for i in l:
        for j in i[::-1]:
            if j == '2':
                j='5'
            elif j == '5':
                j='2'
            elif j not in '18':
                j='?'
            print(j,end=' ')
        print()