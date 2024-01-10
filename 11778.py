import sys
from math import gcd
input=sys.stdin.readline
n,m=map(int,input().split())

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
    
mat1 = SquareMatrix(2)
mat2 = SquareMatrix(2)

mat1.insert(0,0,1)
mat1.insert(1,1,1)

mat2.insert(0,0,1)
mat2.insert(0,1,1)
mat2.insert(1,0,1)

n = gcd(n,m) - 1

while n:
    if n%2:
        mat1 = mat1 * mat2
    mat2 = mat2 * mat2
    n//=2

print(mat1.matrix[0][0])