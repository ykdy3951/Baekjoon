import sys
input=sys.stdin.readline

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
                    if self.matrix[i][k] and other.matrix[k][j]:
                        result.matrix[i][j] = 1
        return result

n, k, m = map(int, input().split())

matrix = SquareMatrix(n)
for _ in range(n):
    a, b = map(int, input().split())
    matrix.insert(_, b - 1, 1)
    matrix.insert(_, a - 1, 1)

result = SquareMatrix(n)
for _ in range(n):
    result.insert(_, _, 1)

while k > 0:
    if k % 2 == 1:
        result = result * matrix
    matrix = matrix * matrix
    k //= 2

for _ in range(m):
    a, b = map(int, input().split())
    print(['life', 'death'][result.matrix[a - 1][b - 1] > 0])
