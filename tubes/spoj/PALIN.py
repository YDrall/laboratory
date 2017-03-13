def is_palindrome(number):
    return str(number) == "".join(reversed(str(number)))

def palin():
   

def palin_naive():
    testcases = int(input())
    for test in range(testcases):
        num = input()
        while True:
            num +=1
            if is_palindrome(num):
                print(num)
                break
