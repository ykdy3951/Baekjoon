def gcd(a, b):
    if a < b:
        a,b=b,a
    while a % b:
        a,b=b,a%b
        if a < b:
            a,b=b,a
    return b

for i in range(int(input())):
    s=0
    l=list(map(int,input().split()))[1:]
    for i in range(len(l)):
        for j in range(i+1, len(l)):
            s+=gcd(l[i],l[j])
    print(s)