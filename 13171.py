import sys
input=sys.stdin.readline
MOD = 1000000007

class Number:
    def __init__(self, n):
        self.n = n % MOD
    
    def __mul__(self, other):
        return Number(self.n * other.n % MOD)
    
    def __pow__(self, n):
        if n == 1:
            return self
        result = self ** (n//2)
        result = result * result
        if n%2 == 1:
            result = result * self
        return result
    
    def __str__(self):
        return str(self.n)

n = Number(int(input()))
print(n**int(input()))