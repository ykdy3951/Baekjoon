import sys
input=sys.stdin.readline

sys.setrecursionlimit(10**6)


parent = [-1 for i in range(100001)]
dist = [0 for i in range(100001)]

def find(x):
    if parent[x] < 0:
        return x
    else:
        px = find(parent[x])
        dist[x] += dist[parent[x]]
        parent[x] = px
        return parent[x]
    
def union(x, y, w):
    px = find(x)
    py = find(y)
    if px == py:
        return
    
    dist[py] = dist[x] - dist[y] + w
    parent[py] = px

while True:
    n, m = map(int, input().split())
    if [0, 0] == [n, m]:
        break

    parent = [-1 for i in range(n+1)]
    dist = [0 for i in range(n+1)]

    for i in range(m):
        l = list(input().split())
        if l[0] == '!':
            union(int(l[1]), int(l[2]), int(l[3]))
        else:
            if find(int(l[1])) == find(int(l[2])):
                print(dist[int(l[2])] - dist[int(l[1])])
            else:
                print("UNKNOWN")
