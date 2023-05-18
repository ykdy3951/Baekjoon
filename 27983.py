N = int(input())
X = list(map(int, input().split()))
L = list(map(int, input().split()))
C = list(input().split())

f = False
ribbon1 = -1
ribbon2 = -1

for i in range(N - 1):
    for j in range(i + 1, N):
        if C[i] != C[j] and abs(X[i] - X[j]) <= L[i] + L[j]:
            f = True
            ribbon1 = i + 1
            ribbon2 = j + 1
            break

if f:
    print("YES")
    print(ribbon1, ribbon2)
else:
    print("NO")