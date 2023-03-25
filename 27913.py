n, q = map(int, input().split())
s = "SciComLove" * (n // 10)
s += "SciComLove"[:n%10]
cnt = s.count("S") + s.count("C") + s.count("L")

for i in range(q):
    x = int(input())
    if s[x - 1].isupper():
        cnt -= 1
        s = s[:x - 1] + s[x - 1].lower() + s[x:]
    else:
        cnt += 1
        s = s[:x - 1] + s[x - 1].upper() + s[x:]
    print(cnt)

