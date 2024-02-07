import sys
input=sys.stdin.readline

MOD = 10000

class SquareMatrix:
    def __init__(self, n, is_identity=False):
        self.n = n
        self.matrix = [[0 for _ in range(n)] for _ in range(n)]
        if is_identity:
            for i in range(n):
                self.matrix[i][i] = 1

    def insert(self, i, j, value):
        self.matrix[i][j] = value

    def __mul__(self, other):
        ret = SquareMatrix(self.n)
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    ret.matrix[i][j] += self.matrix[i][k] * other.matrix[k][j]
                ret.matrix[i][j] %= MOD
        return ret
    
while True:
    n=int(input())

    if n==-1:
        break
    if n==0:
        print(0)
        continue

    n-=1
    matrix = SquareMatrix(2)
    matrix.insert(0, 0, 1)
    matrix.insert(0, 1, 1)
    matrix.insert(1, 0, 1)

    result = SquareMatrix(2, True)

    while n > 0:
        if n % 2 == 1:
            result = result * matrix
        matrix = matrix * matrix
        n //= 2

    print(result.matrix[0][0])