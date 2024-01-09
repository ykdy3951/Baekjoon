import sys
input=sys.stdin.readline
import sys
input=sys.stdin.readline
MOD = 1000

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
l = []
for _ in range(n):
    l.append(list(map(lambda x : int(x) % MOD, input().split())))

matrix = SquareMatrix(n, l) ** m
for i in range(n):
    for j in range(n):
        print(matrix.data[i][j], end=' ')
    print()
