n=5100
k=85
print(433585,316261)
for i in range(n//k):
    for j in range(k):
        print(i*k+j+1, 2*(n+1)+i+1)
for i in range(n//k):
    for j in range(n+1):
        print(2*(n+1)+i+1,j+1+5101)
for i in range(5101):
    print(5101,i+1+5101)