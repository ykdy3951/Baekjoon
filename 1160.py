import sys
input=sys.stdin.readline

m, a, c, x0, cnt, g = map(int, input().split())

class SquareMatrix:
    def __init__(self, n, is_identity=False):
        self.n = n
        self.matrix = [[0]*n for _ in range(n)]
        if is_identity:
            for i in range(n):
                self.matrix[i][i] = 1
        
    def insert(self, i, j, value):
        self.matrix[i][j] = value

    def __mul__(self, other):
        result = SquareMatrix(self.n)
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    result.matrix[i][j] += self.matrix[i][k] * other.matrix[k][j]
                result.matrix[i][j] %= m
    
        return result

    def __str__(self):
        return '\n'.join([' '.join(map(str, row)) for row in self.matrix])

matrix = SquareMatrix(3)
matrix.insert(0, 0, a)
matrix.insert(0, 2, c)
matrix.insert(1, 0, 1)
matrix.insert(2, 2, 1)

result = SquareMatrix(3)
result.insert(0, 0, (a * x0 + c) % m)
result.insert(1, 0, x0)
result.insert(2, 0, 1)

cnt -= 1

while cnt > 0:
    if cnt % 2 == 1:
        result = matrix * result
    matrix = matrix * matrix
    cnt //= 2

print(result.matrix[0][0] % g)