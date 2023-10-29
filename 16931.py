n, m = map(int, input().split())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

arr = [list(map(int, input().split())) for _ in range(n)]

ans = 0
for i in range(n):
    for j in range(m):
        for k in range(4):
            x = i + dx[k]
            y = j + dy[k]
            if x < 0 or x >= n or y < 0 or y >= m:
                ans += arr[i][j]
                continue
            if arr[i][j] > arr[x][y]:
                ans += arr[i][j] - arr[x][y]
ans += n * m * 2
print(ans)