import sys
input=sys.stdin.readline

MOD = 1000000007

class SquareMatrix:
    def __init__(self, n, matrix = None):
        self.n = n
        if matrix == None:
            self.matrix = [[0 for _ in range(n)] for _ in range(n)]
        else:
            self.matrix = matrix

    def insert(self, row, col, value):
        self.matrix[row][col] = value

    def __mul__(self, other):

        result = SquareMatrix(self.n)
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    result.matrix[i][j] += self.matrix[i][k] * other.matrix[k][j] % MOD
        return result
    
    def __str__(self):
        # sum of all elements
        return str(sum(map(sum, self.matrix)) % MOD)

n = int(input()) - 1
matrix = SquareMatrix(3)
matrix.insert(0, 0, 1)
matrix.insert(0, 1, 1)
matrix.insert(0, 2, 1)
matrix.insert(1, 0, 1)
matrix.insert(1, 2, 1)
matrix.insert(2, 0, 1)
matrix.insert(2, 1, 1)

result = SquareMatrix(3)
for i in range(3):
    result.insert(i, i, 1)

while n > 0:
    if n % 2 == 1:
        result = result * matrix
    matrix = matrix * matrix
    n //= 2

print(result)