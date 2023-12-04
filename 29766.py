import re
r=re.compile(r'DKSH')
print(len(r.findall(input())))