# your code goes here
def bishop(n):
    return(2*n-2)
while 1:
    try:
        r=int(raw_input())
    except EOFError:
        break
    if r==1:
        print 1
    else :    
        print(bishop(r))