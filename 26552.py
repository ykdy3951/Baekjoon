for _ in range(int(input())):
    n=int(input())
    n+=1
    while '0' in str(n):
        n+=1
    print(n)