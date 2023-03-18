r=int(input())
d=1 if r > 1900 else 3 if r <= 1600 else 2
s=input()

if str(d) in s:
    print(d)
else:
    for i in s:
        if i < str(d):
            print(i)
        else:
            print(i+'*')