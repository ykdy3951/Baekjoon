import sys
input=sys.stdin.readline
MOD = 1000003

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

n, s, e, t = map(int, input().split())
s-=1; e-=1

matrix = SquareMatrix(n*5)

for i in range(n):
    for j in range(1, 5):
        matrix.insert(i*5+j, i*5+j-1, 1)

for i in range(n):
    for j, v in enumerate(map(int, list(input().rstrip()))):
        if v == 0:
            continue
        matrix.insert(i*5, j*5+v-1, 1)

matrix = matrix**t
print(matrix.data[s*5][e*5])