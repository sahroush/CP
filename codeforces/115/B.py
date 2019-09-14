n, m = map(int, input().split())
s = []
for i in range(n):
	s.append(input())
pos = [(ss.find('W'), ss.rfind('W')) for ss in s]
ans, cur, last, goright = 0, 0, n - 1, True #no type bitch!
while last > 0 and pos[last][0] == -1:
  last = last - 1
ans = last
for lm, rm in pos[0 : last + 1]:
    if lm != -1:
        if goright:
            ans += abs(lm - cur) + rm - lm
            cur = rm
        else:
            ans += abs(rm - cur) + rm - lm
            cur = lm
    goright = not goright
print(ans)