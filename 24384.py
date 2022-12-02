n=int(input())
i=1;s=''
while True:
    s+=str(i**3)
    i+=1
    if len(s) >= n:
        break
print(s[n-1])