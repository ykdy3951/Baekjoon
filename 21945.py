c=0;input()
for i in list(input().split()):
    if i == i[::-1]:
        c+=int(i)
print(c)