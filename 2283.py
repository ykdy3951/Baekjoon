n, k = map(int, input().split())

l = [0] * 1000005
x, y = 1000005, 0
for i in range(n):
    a, b = map(int, input().split())
    x = min(x, a)
    y = max(y, b)
    for j in range(a, b):
        l[j] += 1

fidx, sidx = 0,
val = 0

while fidx <= sidx and sidx <= y:
    if val == k:
        print(fidx, sidx)
        exit(0)
    elif val < k:
        val += l[sidx]
        sidx += 1
    else:
        val -= l[fidx]
        fidx += 1
print(0, 0)