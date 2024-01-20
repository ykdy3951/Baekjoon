import sys
from math import gcd
input=sys.stdin.readline

a, b = map(int, input().split())
c, d = map(int, input().split())

g = gcd(b, d)

x = a * d // g + c * b // g
y = b * d // g

print(x // gcd(x, y), y // gcd(x, y))