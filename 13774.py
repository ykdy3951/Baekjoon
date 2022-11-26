while True:
    l=input()
    if l == '#':
        break
    f=True
    for i in range(len(l)):
        s=l[:i]+l[i+1:]
        if s == s[::-1]:
            f=False
            print(s)
            break
    if f:
        print('not possible')