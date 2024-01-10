import sys
input=sys.stdin.readline

class SquareMatrix:
    def __init__(self, n, matrix = None):
        self.n = n
        if matrix == None:
            self.matrix = [[0 for _ in range(n)] for _ in range(n)]
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
                result.matrix[i][j] %= 1000000007
        return result
    

    def __pow__(self, n):
        if n == 1:
            return self
        result = self ** (n//2)
        result = result * result
        if n%2:
            result = result * self

        return result
    
n, m = map(int, input().split())

matrix = SquareMatrix(m)

for i in range(m - 1):
    matrix.insert(i + 1, i, 1)

matrix.insert(0, 0, 1)
matrix.insert(0, m - 1, 1)

result = SquareMatrix(m)
for i in range(m - 1):
    result.insert(i, i, 1)

while n:
    if n % 2:
        result = result * matrix
    matrix = matrix * matrix
    n //= 2

print(result.matrix[0][0])