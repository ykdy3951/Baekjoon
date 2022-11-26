d={
    '2':'abc',
    '3':'def',
    '4':'ghi',
    '5':'jkl',
    '6':'mno',
    '7':'pqrs',
    '8':'tuv',
    '9':'wxyz'
}
l=[]
for _ in range(int(input())):
    s=''
    for i in input():
        for j in d.keys():
            if i in d[j]:
                s+=j
                break
    l.append(s)
c=0;s=input()
for i in l:
    if s == i:
        c+=1
print(c)