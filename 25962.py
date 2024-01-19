import sys
input=sys.stdin.readline

MOD = 1_000_000_007

class SquareMatrix:
    def __init__(self, n, is_identity=False):
        self.n = n
        self.matrix = [[0]*n for _ in range(n)]
        if is_identity:
            for i in range(n):
                self.matrix[i][i] = 1

    def insert(self, i, j, value):
        self.matrix[i][j] = value

    def update(self, i, j, value):
        self.matrix[i][j] += value
        self.matrix[i][j] %= MOD

    def __mul__(self, other):
        result = SquareMatrix(self.n)
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    result.matrix[i][j] += self.matrix[i][k] * other.matrix[k][j]
                result.matrix[i][j] %= MOD
        return result

    def __str__(self):
        return '\n'.join([' '.join(map(str, row)) for row in self.matrix])

n, m = map(int, input().split())
l = []

for _ in range(m):
    l.append(int(input()))

matrix = SquareMatrix(5)

for i in range(4):
    matrix.insert(i+1, i, 1)

for i in l:
    matrix.update(0, i-1, 1)

result = SquareMatrix(5, True)
while n:
    if n % 2:
        result = result * matrix
    matrix = matrix * matrix
    n //= 2

print(result.matrix[0][0])