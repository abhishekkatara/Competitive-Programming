from fractions import Fraction
import math
 
def modInverse(A, M):
    gcd, x, y = extended_euclid_gcd(A, M)
 
    if x < 0:
        x += M
 
    return x
 
def extended_euclid_gcd(a, b):
    s = 0; old_s = 1
    t = 1; old_t = 0
    r = b; old_r = a
 
    while r != 0:
        quotient = old_r/r
        old_r, r = r, old_r - quotient*r
        old_s, s = s, old_s - quotient*s
        old_t, t = t, old_t - quotient*t
    return [old_r, old_s, old_t]
 
T = int(input())
for i in range(T):
 l, d, t = [int(x) for x in input().split()] 
 
 x=math.acos(d/l)
 tx = x*t
 if tx>6.283185307179586:
  b = tx/6.283185307179586
  tx-=b
 
 h = l * math.cos(tx)
 n = format(h, '.12g')
 res = Fraction(n)
 num,den = res.numerator, res.denominator
 m = 1000000007
 
 r = modInverse(den+m, m)
 
 ans = ((num%m)*(r%m) + m)%m
 
 print(int(ans))