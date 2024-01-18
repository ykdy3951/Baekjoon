import sys
input=sys.stdin.readline
MOD = 31_991
class SquareMatrix:
    def __init__(self, n, is_identity = False):
        self.n = n
        self.is_identity = is_identity
        self.matrix = [[0 for _ in range(n)] for _ in range(n)]
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
                result.matrix[i][j] %= MOD
        return result
    
    def __str__(self):
        return '\n'.join([' '.join([str(i) for i in row]) for row in self.matrix])
    
d, t = map(int, input().split())
matrix = SquareMatrix(d)
result = SquareMatrix(d, True)

for i in range(d):
    matrix.insert(0, i, 1)
    matrix.insert(i, i - 1, 1)

while t > 0:
    if t & 1:
        result = matrix * result
    matrix = matrix * matrix
    t //= 2

print(result.matrix[0][0])