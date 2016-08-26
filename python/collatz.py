from math import log    #for log function

def max_collatz_length(n):
    max = 0
    max_len = 0
    base ={1:1}

    if(type(n) is not int or n is 0):
        return []
    for i in range(n,0,-1):
        len =0
        current = i
        list = []
        while(True):
            if checkbase(base,i):
            	len += base.get(i,0)
                max,max_len =getmax(max, max_len,len,current)
                updatekeys(base,list,len)
                break
            if (i & (i-1)) == 0:    # if exact power of 2
                len += int(log(i,2))+1
                max,max_len = getmax(max,max_len,len,current)
                updatekeys(base,list,len)
                break
            if (i&1) == 0:    # if n is even
                list.append(i)
                i = i/2
                len +=1
            if (i&1)==1:            #if n is odd
                list.append(i)
                i = 3*i +1
                len +=1
    return [max, max_len]

def getmax(max,max_len,len,current):
    if max_len < len:
        max_len = len
        max = current
    return max,max_len


def updatekeys(base,list,len):
	j=0
	for i in list:
		base[i] = len-j;
		j+=1
    
def checkbase(base,key):
    return base.has_key(key)

import time
start = time.time()
ans= max_collatz_length(1000000)
elapsed = time.time() - start

print "ans is: %s, time taken: %s" %(ans,elapsed)