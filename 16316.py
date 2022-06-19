f=True
n=int(input());l=list(input().split())
for i in range(n):
    if l[i] == 'mumble':
        continue
    if int(l[i]) != i + 1:
        f=False
print('makes sense' if f else 'something is fishy')