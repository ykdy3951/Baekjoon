d={
    'a':'e',
    'e':'i',
    'i':'o',
    'o':'u',
    'u':'y',
    'y':'a',
    'A':'E',
    'E':'I',
    'I':'O',
    'O':'U',
    'U':'Y',
    'Y':'A'
}
for _ in range(int(input())):
    s=''
    for i in input():
        if i in d.keys():
            s+=d[i]
        else:
            s+=i
    print(s)