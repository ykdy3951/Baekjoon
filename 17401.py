import sys
input=sys.stdin.readline
MOD = 1_000_000_007

class SquareMatrix:
    def __init__(self, n, is_identity=False):
        self.n = n
        self.matrix = [[0] * n for _ in range(n)]
        if is_identity:
            for i in range(n):
                self.matrix[i][i] = 1

    def insert(self, i, j, values):
        self.matrix[i][j] = values

    def __mul__(self, other):
        result = SquareMatrix(self.n)
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    result.matrix[i][j] += self.matrix[i][k] * other.matrix[k][j]
                result.matrix[i][j] %= MOD
        return result

    def __str__(self):
        return '\n'.join([' '.join(map(str, i)) for i in self.matrix])

def pow(matrix, power):
    result = SquareMatrix(matrix.n, True)
    while power > 0:
        if power & 1:
            result = matrix * result
        matrix = matrix * matrix
        power //= 2
    return result

t, n, d = map(int, input().split())
RBC_maps = [SquareMatrix(n) for _ in range(t+1)]
RBC_maps[0] = SquareMatrix(n, True)

for i in range(1,t+1):
    m = int(input())
    for _ in range(m):
        a, b, c = map(int, input().split())
        RBC_maps[i].insert(a-1, b-1, c)
    RBC_maps[i] = RBC_maps[i-1] * RBC_maps[i]

result = pow(RBC_maps[t], (d // t)) * RBC_maps[d % t]
print(result)