prev = {0: 0, 1: 1}

def fibonacci(n):
    if prev.has_key(n):
        return prev[n]
    else:
        new_value = fibonacci(n-1) + fibonacci(n-2)
        prev[n] = new_value
        return new_value

if __name__ == "__main__":
    from sys import argv
    if len(argv) != 2:
        print "usage: %s range" %(argv[0])
    else:
        print fibonacci(int(argv[1]))

