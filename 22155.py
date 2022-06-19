for _ in range(int(input())):
    a,b=map(int,input().split())
    print('Yes' if max(a,b) < 3 and a+b != 4 else 'No')