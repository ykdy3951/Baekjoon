for _ in range(int(input())):
    l=input()
    f=True
    for i in range(8):
        if i == 4:
            if l[i] < 'A' or l[i] > 'Z':
                f=False
            continue
        if l[i] < '1' or l[i] > '9':
            f=False
            break
    if not f:
        continue
    if f and l[0] == l[1]:
        print(l)