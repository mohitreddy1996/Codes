t=10
while t>0:
    n=long(raw_input())
    diff=long(raw_input())
    if n%2==0 :
        if diff%2==0 :
            print (n+diff)/2
            print (n-diff)/2
        
    else :
        if diff%2==1 :
            print (n+diff)/2
            print (n-diff)/2
    
    t=t-1
    
