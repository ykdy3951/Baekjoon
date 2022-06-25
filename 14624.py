n=int(input())
if n % 2:
    print('*'*n)
    for i in range(n//2,-1,-1):
        print(' '*i+'*',end='')
        if n//2 - i:
            print(' '*(2*(n//2-i)-1)+'*',end='')
        print()
else:
    print('I LOVE CBNU')