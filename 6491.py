import sys
l=[*map(int,sys.stdin.read().split()[:-1])]
for i in l:
    s=sum(j for j in range(1,i) if i % j == 0)
    print(i, 'ABUNDANT' if s > i else 'DEFICIENT' if s < i else 'PERFECT')