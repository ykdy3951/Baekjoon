for _ in range(int(input())):
    d,m=divmod(int(input()),100)
    print('YES' if (d*d+m*m) % 7 == 1 else 'NO')