import sys
input=sys.stdin.readline
MOD = 1000000007
class SquareMatrix:
    def __init__(self, n, matrix = None):
        self.n = n
        if matrix is None:
            self.matrix = [[0] * n for _ in range(n)]
        else:
            self.matrix = matrix

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
    
result = SquareMatrix(2, [[1, 0], [0, 1]])
matrix = SquareMatrix(2, [[1, 1], [1, 0]])

n = int(input()) // 2 * 2
while n:
    if n % 2:
        result = matrix * result
    matrix *= matrix
    n //= 2

print(result.matrix[0][0] - 1)