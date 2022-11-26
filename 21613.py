l=[]
for _ in range(int(input())):
    a=input()
    b=int(input())
    l.append([-b,_,a])
print(sorted(l)[0][2])