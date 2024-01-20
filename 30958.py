import sys
from collections import Counter
input=sys.stdin.readline

n=int(input())
s=input().rstrip().replace(' ', '').replace(',', '').replace('.', '')
print(Counter(s).most_common(1)[0][1])