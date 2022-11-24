input()
l=list(map(int,input().split()))
print('yes' if l == sorted(l) else 'no')