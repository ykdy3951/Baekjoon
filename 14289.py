import sys
input=sys.stdin.readline
MOD = 1000000007


class SquareMatrix:
    def __init__(self, n, data = None):
        self.n = n
        if data == None:
            self.data = [[0 for _ in range(n)] for _ in range(n)]
        else:
            self.data = data

    def insert(self, i, j, value):
        self.data[i][j] = value
    
    def __mul__(self, other):
        if self.n != other.n:
            raise ValueError
        result = [[0 for _ in range(other.n)] for _ in range(self.n)]
        for i in range(self.n):
            for j in range(other.n):
                for k in range(self.n):
                    result[i][j] += self.data[i][k] * other.data[k][j]
                    result[i][j] %= MOD
        return SquareMatrix(self.n, result)

    def __pow__(self, n):
        if n == 1:
            return self
        result = self**(n//2)
        result = result * result
        if n%2 == 1:
            result = result * self
        return result

n, m = map(int, input().split())
matrix = SquareMatrix(n)

for _ in range(m):
    a, b = map(int, input().split())
    matrix.insert(a-1, b-1, 1)
    matrix.insert(b-1, a-1, 1)

d = int(input())
matrix = matrix**d
print(matrix.data[0][0])