l=input()
for i in l:
    if i >= 'A' and i <= 'Z':
        print(chr((ord(i)-52)%26+65),end='')
    elif i >= 'a' and i <= 'z':
        print(chr((ord(i)-84)%26+97),end='')
    else:
        print(i,end='')
print()