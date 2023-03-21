for _ in range(int(input())):
	n,p,q=map(int,input().split())
	l=[0]+sorted(list(map(int,input().split())))
	a = -1
	for i in range(1, n+1):
		l[i] += l[i-1]
		if l[i] > q:
			a = i-1
			break
	if a == -1:
		a = n
	print(f'Case {_+1}: {min(p, a)}')
