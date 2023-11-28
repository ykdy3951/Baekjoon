import sys
input=sys.stdin.readline
n=int(input())
s=input()

k = [0] * (1000001)
ck = [0] * (1000001)
ock = [0] * (1000001)

for i in range(n-1, -1, -1):
    if i != n-1:
        k[i] = k[i+1]
        ck[i] = ck[i+1]
        ock[i] = ock[i+1]
    if s[i] == 'K':
        k[i] += 1
    elif s[i] == 'C':
        ck[i] += k[i]
    elif s[i] == 'O':
        ock[i] += ck[i]

ans = 0
tmp = 1
for i in range(n):
    if s[i] == 'R':
        ans += tmp * ock[i]
    tmp = (2 * tmp) % (10**9+7)
print(ans % (10**9+7))