from queue import PriorityQueue

pq = PriorityQueue()
n, h, t = map(int, input().split())
ans = 0
cnt = t
for i in range(n):
    pq.put(-int(input()))

for i in range(t):
    a = -pq.get()
    if a < h:
        cnt = i
        pq.put(-a)
        break
    if a == 1:
        pq.put(-1)
        break
    pq.put(-(a//2))

a = -pq.get()
if a < h:
    print('YES')
    print(cnt)
else:
    print('NO')
    print(a)