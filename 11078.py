s=input();a='';b=0
for i in input():
    if b > len(s):
        break
    if i >= 'a' and i <= 'z':
        a+=s[b:b+ord(i)-96]
        b+=ord(i)-96
    else:
        b+=ord(i)-64
t=0
for i in a:
    t+=int(i)
print('non sequitur' if b != len(s) else t)