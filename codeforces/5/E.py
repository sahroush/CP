n = int(input())
hill = tuple(map(int, input().split()))
pairs = 0
highest, at = max((h, k) for k, h in enumerate(hill))
last = highest
count = 0
p = list()
push = p.append
pop = p.pop
for at in range(at - 1, at - n, -1):
    current = hill[at]
    while current > last:
        pairs += count
        last, count = pop()
    if current == last:
        count += 1
        pairs += count
    else:
        pairs += 1
        push((last, count))
        last = current
        count = 1
push((last, count))
end = len(p)
pairs += sum(p[k][1]
             for k in range((1 if p[0][1] else 2), end))
print(pairs)