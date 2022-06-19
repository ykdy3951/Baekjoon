for _ in range(int(input())):
    a,b,c=0,0,0
    for i in range(10):
        i,j,k=map(int,input().split())
        a+=i;b+=j;c+=k
    print(a//10+(a%10)//5,b//10+(b%10)//5,c//10+(c%10)//5)