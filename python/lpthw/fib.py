def fibonacci(n):
	print n
	if n == 0 or n == 1:
		return 1
	else:
		return fibonacci(n-1) + fibonacci(n-2)

if __name__ == "__main__":
    from sys import argv
    print fibonacci(int(argv[1]))



