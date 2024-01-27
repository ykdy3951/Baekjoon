import sys
input=sys.stdin.readline

sh1, sm1, eh1, em1 = map(int, input().split())
t1 = (eh1 - sh1) * 60 + (em1 - sm1)
t1 = t1 if t1 >= 0 else 24 * 60 + t1
sh2, sm2, eh2, em2 = map(int, input().split())
t2 = (eh2 - sh2) * 60 + (em2 - sm2)
t2 = t2 if t2 >= 0 else 24 * 60 + t2
sh3, sm3, eh3, em3 = map(int, input().split())
t3 = (eh3 - sh3) * 60 + (em3 - sm3)
t3 = t3 if t3 >= 0 else 24 * 60 + t3
h1, m1 = divmod(min(t1, t2, t3), 60)
h2, m2 = divmod(max(t1, t2, t3), 60)
print("%02d:%02d" % (h1, m1))
print("%02d:%02d" % (h2, m2))