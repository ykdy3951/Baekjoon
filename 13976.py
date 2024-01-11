import sys
input=sys.stdin.readline

MOD = 1000000007

class SquareMatrix:
    def __init__(self, n, matrix = None):
        self.size = n
        if matrix == None:
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

if n % 2:
    print(0)
    exit()

n //= 2
n -= 1

matrix = SquareMatrix(2, [[4, -1], [1, 0]])
result = SquareMatrix(2, [[3, 0], [1, 0]])

while n > 0:
    if n % 2:
        result = matrix * result
    matrix = matrix * matrix
    n //= 2

print(result.matrix[0][0])