n=int(input())

arr = [list(map(int,input().split())) for _ in range(n)]

def area_triangle(points):
    return abs(points[0][0]*points[1][1] + points[1][0]*points[2][1] + points[2][0]*points[0][1] - points[0][1]*points[1][0] - points[1][1]*points[2][0] - points[2][1]*points[0][0]) / 2

m=0
for i in range(n-2):
    for j in range(i+1, n-1):
        for k in range(j+1, n):
            m=max(m, area_triangle([arr[i], arr[j], arr[k]]))
print(m)