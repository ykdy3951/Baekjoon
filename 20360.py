l=bin(int(input()))[2:][::-1];k=0
for i in l:
    if i == '1':
        print(k, end=' ')
    k+=1