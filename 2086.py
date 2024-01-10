import sys
input=sys.stdin.readline
MOD = 1000000000

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
        n = self.n
        result = SquareMatrix(n)
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    result.matrix[i][j] += self.matrix[i][k] * other.matrix[k][j]
                result.matrix[i][j] %= MOD
        return result
    
    def __pow__(self, m):
        if m == 1:
            return self
        result = self ** (m // 2)
        result = result * result
        if m % 2:
            result = result * self
        return result
    
a, b = map(int, input().split())
a-=1; b-=1; a+=1; b+=2
mat1 = SquareMatrix(2)
mat1.insert(0, 0, 1)
mat1.insert(1, 1, 1)

mat2 = SquareMatrix(2)
mat2.insert(0, 0, 1)
mat2.insert(0, 1, 1)
mat2.insert(1, 0, 1)

while b > 0:
    if b % 2:
        mat1 = mat1 * mat2
    mat2 = mat2 * mat2
    b //= 2

mat3 = SquareMatrix(2)
mat3.insert(0, 0, 1)
mat3.insert(1, 1, 1)

mat4 = SquareMatrix(2)
mat4.insert(0, 0, 1)
mat4.insert(0, 1, 1)
mat4.insert(1, 0, 1)

while a > 0:
    if a % 2:
        mat3 = mat3 * mat4
    mat4 = mat4 * mat4
    a //= 2

print(str((mat1.matrix[0][0] - mat3.matrix[0][0] + MOD) % MOD)[-9:])
