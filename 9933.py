n=int(input())
l=[];ans=""
for i in range(n):
    s=input()
    if s == s[::-1] or s[::-1] in l:
        print(len(s), s[len(s)//2])
        break
    l.append(s)