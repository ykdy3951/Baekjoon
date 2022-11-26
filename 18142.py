l=[]
for i in list(input().split()):
    if i not in ['bubble','tapioka']:
        l.append(i)
if l == []:
    l.append('nothing')
print(*l)