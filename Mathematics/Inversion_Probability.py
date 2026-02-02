from fractions import Fraction


n = int(input())
r = list(map(int, input().strip().split(' ')))

ans = 0
for i in range(len(r)):
    for j in range(i + 1, len(r)):
        if r[i] < r[j]:
            ans += Fraction(r[i]-1, 2*r[j])
        else:
            ans += 1 - Fraction(r[j]+1, 2*r[i])

res = float(round(ans, 6))
print(f"{res:.6f}")

