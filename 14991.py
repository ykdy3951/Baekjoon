s=1;input()
for i in list(map(int,input().split())):
    s*=2
    s-=i
    if s < 0:
        s=-1
        break
print(s%(1000000007) if s != -1 else 'error')