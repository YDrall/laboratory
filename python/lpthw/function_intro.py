from sys import argv

#function with arg list
def print_list(*args):
    print "print_list called:\n printing all arguments"
    for arg in args:
        print arg

#function with two arguments as parameters
def print_two_arg(arg1, arg2):
    print "arg1 is: %r, and arg2 is %r" %(arg1, arg2)

#function without any argument
def print_no_arg():
    print "I do nothing"

print_list(argv)
print_two_arg(argv[1],argv[2])
print_no_arg()

