# your code goes here# cook your code here
from numpy import *
t=int(raw_input())
while(t>0):
    m=raw_input()
    m=m.split(' ')
    x=long(m[0])
    m[0]=long(m[0])
    n=long(m[1])
    m[1]=long(m[1])
    if x%2:
        m[0]=m[0]/2 + 1
    else:
        m[0]=m[0]/2
    if n%2:
        m[1]=m[1]/2 + 1
    else:
        m[1]=m[1]/2
    print max(m[0]*n,m[1]*x)
    t=t-1
    
