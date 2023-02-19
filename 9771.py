l=list(open(0))
c=0
word=l[0].rstrip()
l=l[1:]
for i in l:
    i=i.rstrip()
    c+=i.count(word)
print(c)