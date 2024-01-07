import sys
input=sys.stdin.readline
for _ in range(int(input())):
    n=int(input())
    m=n+1
    print(['Bye','Good'][m%(n%100)==0])
    