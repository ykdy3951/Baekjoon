n=int(input())
s=input()
l=[987654321]*n
l[0]=0
b=[];o=[];j=[]
b.append(0)

for i in range(1, n):
    if s[i] == 'O':
        for x in b:
            l[i] = min(l[i],l[x]+(i-x)**2)
        o.append(i)
    if s[i] == 'J' and o != []:
        for x in o:
            l[i] = min(l[i], l[x]+(i-x)**2)
        j.append(i)
    if s[i] == 'B' and j != []:
        for x in j:
            l[i] = min(l[i], l[x]+(i-x)**2)    
        b.append(i)
print(l[n-1] if l[n-1] != 987654321 else -1)