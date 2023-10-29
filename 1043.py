n,m=map(int,input().split())
know = list(map(int,input().split()))[1:]
visit = [False for _ in range(n+1)]
ans = 0
party = []
graph = [[] for _ in range(n+1)]

for _ in range(m):
    party.append(list(map(int,input().split()))[1:])
    for i in range(len(party[-1])):
        for j in range(i+1,len(party[-1])):
            graph[party[-1][i]].append(party[-1][j])
            graph[party[-1][j]].append(party[-1][i])

for i in know:
    stack = [i]
    while stack:
        node = stack.pop()
        if visit[node]:
            continue
        visit[node] = True
        for j in graph[node]:
            if not visit[j]:
                stack.append(j)

for i in party:
    flag = True
    for j in i:
        if visit[j]:
            flag = False
            break
    if flag:
        ans += 1

print(ans)