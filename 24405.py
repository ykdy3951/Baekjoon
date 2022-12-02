l=input()
a=l.index('(')
b=len(l)-1-l.index(')')
print('correct' if a == b else 'fix')