import sys
input=sys.stdin.readline

y,m,d=map(int,input().split('-'))
n = int(input())

all_day = y * 360 + (m - 1) * 30 + d - 1 + n
y = all_day // 360
all_day %= 360
m = all_day // 30 + 1
d = all_day % 30 + 1
print("%04d-%02d-%02d" % (y, m, d))