f = [1]
for i in range(1, 40):
    f.append(f[i - 1] * i)

ans = set()

def go(rem, d, last, prod):
    if d == 0:
        ans.add(prod // f[rem])
        return
    for i in range(last, rem + 1):
        go(rem - i, d - 1, i, prod // f[i])

d, h = map(int, input().split())
go(h - 1, d - 1, 0, f[h - 1])
for x in sorted(ans):
    print(x)
