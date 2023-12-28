import sys
input=sys.stdin.readline
for _ in range(int(input())):
    a=int(input())
    [input() for _ in range(a)]
    b=int(input())
    [input() for _ in range(b)]
    print('yes' if a==b else 'no')