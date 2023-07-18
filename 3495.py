h,w=map(int,input().split())
b=[input() for _ in range(h)]
n=0
for i in range(h):
    s=0
    for j in range(w):
        if b[i][j] == '/' or b[i][j] == '\\':
            s+=1
            n+=1
        if s%2 and b[i][j] == '.':
            n+=2
print(n//2)