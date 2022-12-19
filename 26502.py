d={
    'a':'e',
    'e':'i',
    'i':'o',
    'o':'u',
    'u':'y',
    'y':'a'
}
for _ in range(int(input())):
    s=''
    for i in input():
        if i in d.keys():
            s+=d[i]
        else:
            s+=i
    print(s)