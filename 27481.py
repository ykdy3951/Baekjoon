n=int(input())
s=input()

l=[0]*10
for i in s:
    if i == 'L':
        s=0
        while True:
            if l[s] == 0:
                l[s]=1
                break
            s+=1
    elif i == 'R':
        s=9
        while True:
            if l[s] == 0:
                l[s]=1
                break
            s-=1
    else:
        l[int(i)]=0
print(''.join(map(str, l)))