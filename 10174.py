for _ in range(int(input())):
    i=input().lower()
    a=i[:len(i)//2+len(i)%2];b=i[len(i)//2:][::-1]
    print('Yes' if a == b else 'No')