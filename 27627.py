s=input()
f=False
for i in range(1, len(s)):
    x=s[:i]
    y=s[i:]
    if x == x[::-1] and y == y[::-1]:
        f=True
        print(x, y)
        break
if not f:
    print('NO')