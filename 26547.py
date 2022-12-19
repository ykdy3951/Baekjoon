for _ in range(int(input())):
    s=input()
    if len(s) == 1:
        print(s)
        continue
    print(s)
    for i in range(1,len(s)-1):
        print(s[i]+' '*(len(s)-2)+s[len(s)-1-i])
    print(s[::-1])