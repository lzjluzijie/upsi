from math import comb
from decimal import Decimal

ns = 2 ** 24
nr = 2 ** 8
m = 2 ** 8
d = 128
sigma = Decimal(-40)
negl = 2 ** sigma

p = (1 - 1 / Decimal(m)) ** nr
print("p =", p)

w = 128
while True:
    prob = Decimal(0)
    for k in range(d):
        prob += Decimal(comb(w, k)) * (p ** k) * ((1 - p) ** (w - k))
    prob *= ns
    print (w, prob)
    w += 1

    if prob < negl:
        break
