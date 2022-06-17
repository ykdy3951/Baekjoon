a,b=map(int,input().split())
d,s=map(int,input().split())
i=(a*d-s*b)/(a-b)
print(i if i >= 0 and i <= 100 else 'impossible')