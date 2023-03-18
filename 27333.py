n=int(input())
s=input()

i=0
a=''
while True:
    if i >= n:
        break
    if i < n-1:
        if s[i] == s[i+1]:
            a+=s[i].upper()*2
            i+=1
        else:
            a+=s[i]
    else:
        a+=s[i]
    i+=1
print(a)