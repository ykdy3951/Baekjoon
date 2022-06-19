l=list(map(int,open(0)))
for i in l[:-1]:
    if i == 1916 or i == 1940 or i == 1944:
        print(i,'Games cancelled')
    elif i % 4 == 0 and i >= 1896:
        if i <= 2020:
            print(i, 'Summer Olympics')
        else:
            print(i, 'No city yet chosen')
    else:
        print(i, 'No summer games')