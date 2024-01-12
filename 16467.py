import sys
input=sys.stdin.readline

MOD = 100_000_007

class SquareMatrix:
    def __init__(self, n, matrix = None):
        self.n = n
        if matrix == None:
            self.matrix = [[0 for _ in range(n)] for _ in range(n)]
        else:
            self.matrix = matrix
    
    def insert(self, i, j, value):
        self.matrix[i][j] = value

    def update(self, i, j, value):
        self.matrix[i][j] += value

    def __mul__(self, other):
        result = SquareMatrix(self.n)
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    result.matrix[i][j] += self.matrix[i][k] * other.matrix[k][j]
                result.matrix[i][j] %= MOD
        return result
    
for _ in range(int(input())):
    k, n = map(int,input().split())
    matrix = SquareMatrix(k+1)

    for i in range(k):
        matrix.insert(i+1, i, 1)

    matrix.update(0, k, 1)
    matrix.update(0, 0, 1)

    result = SquareMatrix(k+1)
    for i in range(k+1):
        result.insert(i, i, 1)
        
    while n > 0:
        if n % 2 == 1:
            result = matrix * result
        matrix = matrix * matrix
        n//=2

    print(result.matrix[0][0])