def numeric_palindrome(*args):
    length = len(args)
    max_pal = 0
    print "input is: ", args
    for n in range(1,length):		#generate all permutations of [args]
        #print "n= ",n
        for i in range(length-n):
            #print "i= ",i
            for k in range(length):
            	print "$"*20
            	if k+n+1 >length:
            	    break
            	base_product = get_product(args,k+i,n)*args[i]	#get base value to multiply with each term in [args]
            	print "#"*8, "generating all possible permutations","#"*8
            	for j in range(0,i)+range(n,length):
            		#print "j= ",j
            		print "product= %d * %d = %d"%(base_product,args[j],base_product*args[j])
            		max_pal = max(get_pal(args[j]*base_product),max_pal)


    return max_pal
            
def get_product(args,k,n):
    product= 1
    b = []
    for j in range(n):
        product *= args[k+j]
        b.append(args[k+j])
    print "base =",b," = ",product
    return product

def get_pal(num):
	left = []
	right = []
	lst = [0,0,0,0,0,0,0,0,0,0]

	while num:
		lst[num%10] += 1
		num = num/10
	
	for i in range(9,-1,-1):
		if len(left) ==0 and i ==0:
			break
		while lst[i] >1:
			left.append(i)
			right.insert(0,i)
			lst[i] = lst[i]-2

	for i in range(9,-1,-1):
		if lst[i] > 0:
			left.append(i)
			break
	
	for i in right:
		left.append(i)

	return convert_list_to_numeric(left)


def convert_list_to_numeric(pal):
	num = 0
	for i in pal:
		num = num*10 +int(i)
	print "output palindrome number is: ",num
	return num
#get_pal(492758503359879389946469200)
#print "max palindrome found: %d"%(numeric_palindrome(5, 38, 17, 95, 88671, 586, 73518, 517, 66))
#print numeric_palindrome(9, 61867)
print numeric_palindrome(657,892)