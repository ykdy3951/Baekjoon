import sys
input=sys.stdin.readline

MOD = 1_234_567_891

class SquareMatrix:
    def __init__(self, n, is_identity=False):
        self.n = n
        self.matrix = [[0] * n for _ in range(n)]
        if is_identity:
            for i in range(n):
                self.matrix[i][i] = 1
    
    def insert(self, i, j, value):
        self.matrix[i][j] = value

    def __mul__(self, other):
        result = SquareMatrix(self.n)
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    result.matrix[i][j] += self.matrix[i][k] * other.matrix[k][j]
                result.matrix[i][j] %= MOD
        return result

n, l = map(int, input().split()); l-=1
val = [*map(int, input().split())]

val44, val47, val74, val77 = 0, 0, 0, 0

tmp = []

for i in val:
    s = str(i)

    if len(s) != (s.count('4') + s.count('7')):
        continue
    
    if i in tmp:
        continue

    tmp.append(i)

    if s[0] == s[-1] and s[0] == '4':
        val44 += 1
    elif s[0] == s[-1] and s[0] == '7':
        val77 += 1
    elif s[0] == '4' and s[-1] == '7':
        val47 += 1
    elif s[0] == '7' and s[-1] == '4':
        val74 += 1

matrix = SquareMatrix(2)
matrix.insert(0, 0, val44)
matrix.insert(0, 1, val74)
matrix.insert(1, 0, val47)
matrix.insert(1, 1, val77)

result = SquareMatrix(2)
result.insert(0, 0, val44 + val74)
result.insert(1, 0, val47 + val77)

while l > 0:
    if l & 1:
        result = matrix * result
    matrix = matrix * matrix
    l >>= 1

print((result.matrix[0][0] + result.matrix[1][0]) % MOD)
