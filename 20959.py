import re
p=re.compile('[0-9]+')
l=[]
for i in p.findall(input()):
    if i not in l:
        l.append(i)
print(len(l))