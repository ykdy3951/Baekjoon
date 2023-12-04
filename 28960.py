h,l,a,b=map(int,input().split())
print(['NO','YES'][(a<=h*2 and b<=l) or (b<=h*2 and a<=l)])
