n=int(input())
for i in input():
    if i >= 'a' and i <= 'z':
        print(chr((ord(i)-71-n)%26+97),end='')
        n+=1
        if n == 26:
            n=1
    else:
        print(i,end='')