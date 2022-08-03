for _ in range(int(input())):
    a=input()
    print(a[:(a.index('D') if 'D' in a else len(a))].count('U'))