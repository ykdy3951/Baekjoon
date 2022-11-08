s=input()
l=[]
for i in range(len(s)):
    l.append(s[i:])
print('\n'.join(sorted(l)))