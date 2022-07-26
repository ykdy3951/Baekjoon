a,b=map(int,input().split())
if a > b:
    b,a=a,b
for i in range(1, b-a+2):
    print(i+a)