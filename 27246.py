n=1
c=0
s=0

k=int(input())
while True:
    if s + n*n > k:
        print(c)
        break
    s+=n*n
    c+=1
    n+=1