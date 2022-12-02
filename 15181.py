l=[2,4,6]

while True:
    i=input()
    if i == '#':
        break
    t=[]
    for j in range(1,len(i)):
        if ord(i[j])-ord(i[j-1]) < 0:
            t.append(ord(i[j])-ord(i[j-1])+7)
        else:
            t.append(ord(i[j])-ord(i[j-1]))
    if t == []:
        print('That music is beautiful.')
        continue
    flag=True
    for i in t:
        if i not in l:
            flag=False
            break
    if flag:
        print('That music is beautiful.')
    else:
        print('Ouch! That hurts my ears.')