while True:
    i=input()
    if i == 'quit!':
        break
    if len(i) >= 4 and i[-2:] == 'or' and i[-3] not in 'aeiou':
        i=i[:-2]+'our'
    print(i)