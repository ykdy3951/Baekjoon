x=list(open(0))
l=''.join([t.strip() for t in x])
print(l.count('P')-l.count('p')+3*(l.count('N')+l.count('B')-l.count('n')-l.count('b'))+5*l.count('R')-5*l.count('r')+9*l.count('Q')-9*l.count('q'))