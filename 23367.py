l=['qwertasdfgzxcvb','yuiophjklnm']
a=True;s=input()
f=int(s[0] in l[1])
for i in range(len(s)):
    if i % 2:
        if s[i] not in l[1-f]:
            a=False
            break
    else:
        if s[i] not in l[f]:
            a=False
            break
print('yes' if a else 'no')