n=int(input())
x=list(map(int,input().split()))
y=list(map(int,input().split()))
for i in x:
    if i not in y:
        print(i)
        break