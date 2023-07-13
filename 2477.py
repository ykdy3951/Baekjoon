k=int(input())
arr = [list(map(int,input().split())) for _ in range(6)]

w = [0, 0]
h = [0, 0]
for i in range(6):
    if arr[i][0] < 3:
        if arr[i][1] > w[0]:
            w[0] = arr[i][1]
            w[1] = i
    else:
        if arr[i][1] > h[0]:
            h[0] = arr[i][1]
            h[1] = i
min_w = abs(arr[w[1]-1][1] - arr[(w[1]+1)%6][1])
min_h = abs(arr[h[1]-1][1] - arr[(h[1]+1)%6][1])
print((w[0]*h[0] - min_w*min_h)*k)