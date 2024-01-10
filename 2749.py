import sys
input=sys.stdin.readline
MOD = 1000000
sys.setrecursionlimit(10**6)

class SquareMatrix:
    def __init__(self, n, data = None):
        self.n = n
        if data is None:
            self.data = [[0] * n for _ in range(n)]
        else:
            self.data = data
    
    def insert(self, i, j, value):
        self.data[i][j] = value

    def __mul__(self, other):
        n = self.n
        result = SquareMatrix(n)
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    result.data[i][j] += self.data[i][k] * other.data[k][j]
                result.data[i][j] %= MOD
        return result
    
    def __pow__(self, m):
        if m == 1:
            return self
        result = self ** (m // 2)
        result = result * result
        if m % 2:
            result = result * self
        return result

n=int(input())-1

mat1 = SquareMatrix(2)
mat1.insert(0, 0, 1)
mat1.insert(1, 1, 1)

mat2 = SquareMatrix(2)
mat2.insert(0, 0, 1)
mat2.insert(1, 0, 1)
mat2.insert(0, 1, 1)
mat2.insert(1, 1, 0)

while n:
    if n % 2:
        mat1 = mat1 * mat2
    mat2 = mat2 * mat2
    n //= 2

print(mat1.data[0][0])