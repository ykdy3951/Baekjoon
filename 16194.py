import sys
input=sys.stdin.readline
n=int(input())

l=[0]+list(map(int, input().split()))
d=[l[i] for i in range(n+1)]

for i in range(1, n+1):
    for j in range(1, i+1):
        d[i] = min(d[i], d[i - j] + l[j])

print(d[n])