# cook your dish here
from fractions import gcd


t=int(input())
while t>0 :
    x=input().split(' ')
    n=int(x[0])
    m=int(x[1])
    print(gcd(n,m))
    t=t-1
    