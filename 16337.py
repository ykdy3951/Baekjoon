d={
    1:[[':::',':o:',':::']],
    2:[['o::',':::','::o'],['::o',':::','o::']],
    3:[['o::',':o:','::o'],['::o',':o:','o::']],
    4:[['o:o',':::','o:o']],
    5:[['o:o',':o:','o:o']],
    6:[['ooo',':::','ooo'],['o:o','o:o','o:o']]
}
l=[];f=False
for _ in range(3):
    l.append(input())
for i in range(1,7):
    for j in d[i]:
        if l == j:
            print(i)
            f=True
            break
if not f:
    print('unknown')