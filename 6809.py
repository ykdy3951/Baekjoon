import sys
input=sys.stdin.readline

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
        return SquareMatrix(self.n, result)

    def __pow__(self, n):
        if n == 1:
            return self
        result = self**(n//2)
        result = result * result
        if n%2 == 1:
            result = result * self
        return result
    
a = SquareMatrix(27)
for i in range(27):
    t=min(ord(input().rstrip())-65, 26)
    a.insert(i, t, 1)
a = a ** int(input())
s = input().rstrip()

d={}
for i in range(26):
    for j in range(27):
        if a.data[i][j] == 1:
            d[chr(i+65)] = chr(j+65) if j != 26 else '_'
for i in range(27):
    if a.data[26][i]:
        d['_'] = chr(i+65) if i != 26 else '_'

for i in s:
    print(d[i],end='')