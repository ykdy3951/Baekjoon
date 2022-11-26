n=int(input())//364
for i in range(min(n-1,100),-1,-1):
    if (n-i)%3 == 0:
        print(i)
        print((n-i)//3)
        break