import sys
input=sys.stdin.readline

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
    

    def __pow__(self, n):
        if n == 1:
            return self
        result = self ** (n//2)
        result = result * result
        if n%2:
            result = result * self

        return result
    
d = int(input())

matrix = [
    [0, 1, 1, 0, 0, 0, 0, 0], # 정보과학관
    [1, 0, 1, 1, 0, 0, 0, 0], # 전산관
    [1, 1, 0, 1, 1, 0, 0, 0], # 미래관
    [0, 1, 1, 0, 1, 1, 0, 0], # 신양관
    [0, 0, 1, 1, 0, 1, 0, 1], # 한경직기념관
    [0, 0, 0, 1, 1, 0, 1, 0], # 진리관
    [0, 0, 0, 0, 0, 1, 0, 1], # 학생회관
    [0, 0, 0, 0, 1, 0, 1, 0], # 형남공학관
]

matrix = SquareMatrix(8, matrix)
print((matrix ** d).matrix[0][0])