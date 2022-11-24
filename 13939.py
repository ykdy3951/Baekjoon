import re
n=int(input())
l=list(input().replace('?','.').replace('!','.').split('.'))
p=re.compile('[A-Z]{1}[a-z]* ')
for i in l[:-1]:
    i+=' '
    print(len(p.findall(i)))