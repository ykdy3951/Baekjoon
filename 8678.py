for _ in range(int(input())):
    a,b=map(int,input().split())
    if b % a:
        print('NIE')
    else:
        print('TAK')