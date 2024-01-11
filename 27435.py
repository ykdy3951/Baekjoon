import sys
input=sys.stdin.readline

MOD = 998244353

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
    
    def __str__(self):
        return '\n'.join([' '.join(map(str, row)) for row in self.matrix])

for _ in range(int(input())):
    n = int(input()) + 1
    matrix = SquareMatrix(3, [[0, 1, 1], [1, 0, 0], [0, 1, 0]])
    result = SquareMatrix(3, [[1, 0, 0], [0, 1, 0], [0, 0, 1]])

    while n:
        if n % 2:
            result = matrix * result
        matrix *= matrix
        n //= 2
    
    print(result.matrix[0][0])