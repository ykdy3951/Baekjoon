x={
    'I':1,
    'V':5,
    'X':10,
    'L':50,
    'C':100,
    'D':500,
    'M':1000
}
for i in range(int(input())):
    l=input();s=0
    for j in x.keys():
        s+=x[j]*l.count(j)
    print(s)