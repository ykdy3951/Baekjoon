n,u,l=map(int,input().split())
a=n>=1000
b=u>=8000 or l>=260
print('Very Good' if a and b else 'Good' if a else 'Bad')