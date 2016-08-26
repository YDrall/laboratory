#
# infinite recursion
#

def recursion_depth(number):
    print "Recursion depth number: %d" %(number)
    recursion_depth(number+1)

if __name__ == "__main__":
    recursion_depth(0)

