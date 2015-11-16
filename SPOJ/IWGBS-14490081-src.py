# cook your code here
n=int(raw_input())
l=[0]*(10004)
l[0]=1
l[1]=2
for i in range(2,n+1):
    l[i]=l[i-1]+l[i-2]

print l[n]    