import sys
input=sys.stdin.readline

class SquareMatrix:
    def __init__(self, n, mod, is_identity=False):
        self.n = n
        self.mod = mod
        self.matrix = [[0] * n for _ in range(n)]
        if is_identity:
            for i in range(n):
                self.matrix[i][i] = 1

    def insert(self, i, j, value):
        self.matrix[i][j] = value

    def __mul__(self, other):
        result = SquareMatrix(self.n, self.mod)
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    result.matrix[i][j] += self.matrix[i][k] * other.matrix[k][j]
                if result.matrix[i][j] >= self.mod:
                    result.matrix[i][j] %= self.mod
        return result

while True:
    n,m,a,b,c,t=map(int,input().split())
    if [n,m,a,b,c,t]==[0]*6:break

    matrix = SquareMatrix(n + 2, m)
    for i in range(1, n+1):
        matrix.insert(i, i - 1, a)
        matrix.insert(i, i, b)
        matrix.insert(i, i + 1, c)

    result = SquareMatrix(n + 2, m)
    for i, val in enumerate(map(int, input().split())):
        result.insert(i + 1, 0, val)

    while t > 0:
        if t & 1:
            result = matrix * result
        matrix = matrix * matrix
        t //= 2

    for i in range(1, n+1):
        print(result.matrix[i][0], end=' ')
    print()