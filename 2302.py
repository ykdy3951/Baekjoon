import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
l=[0]
for i in range(m):
    l.append(int(input()))
l.append(n+1)
x = [0] * (n + 1)
x[0] = x[1] = 1

for i in range(2, n+1):
    x[i] = x[i-1] + x[i-2]

ans = 1
for i in range(1, m+2):
    ans *= x[(l[i]-l[i-1]-1)]
print(ans)
