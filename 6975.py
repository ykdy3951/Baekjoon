for _ in range(int(input())):
    n=int(input());s=0
    for i in range(1,n):
        if n % i == 0:
            s+=i
    print(n,'is a deficient number.' if s < n else 'is an abundant number.' if s > n else 'is a perfect number.')
    print()