import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    a, b = map(int, input().split());a %= b
    s, e = map(int, input().split())

    ans = ""

    t = pow(10, s-1, b)
    for i in range(s, s + e):
        ans += str(((a * t) % b) * 10 // b)
        t *= 10
        t %= b
    print(ans)