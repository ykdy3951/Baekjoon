a,b=map(int,input().split(':'))
x,y=map(int,input().split(':'))
print(['YES','NO'][a<x or y>b])