import sys
input=sys.stdin.readline

MOD = 1000000007

class SquareMatrix:
    def __init__(self, n, matrix = None):
        self.size = n
        if matrix is None:
            self.matrix = [[0 for _ in range(n)] for _ in range(n)]
        else:
            self.matrix = matrix

    def insert(self, x, y, value):
        self.matrix[x][y] = value

    def __mul__(self, other):
        result = SquareMatrix(self.size)
        for i in range(self.size):
            for j in range(self.size):
                for k in range(self.size):
                    result.matrix[i][j] += self.matrix[i][k] * other.matrix[k][j]
                result.matrix[i][j] %= MOD
        return result

n = int(input()) 

matrix = SquareMatrix(2)
matrix.insert(0, 0, 1)
matrix.insert(0, 1, 1)
matrix.insert(1, 0, 1)

result = SquareMatrix(2)
result.insert(0, 0, 1)
result.insert(1, 1, 1)

while n > 0:
    if n % 2 == 1:
        result = result * matrix
    matrix = matrix * matrix
    n //= 2

print((result.matrix[0][0] * result.matrix[1][0]) % MOD)