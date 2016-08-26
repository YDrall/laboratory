def valid_parentheses(string):
	stack = []
	for ch in string:
		if ch == '(':
			stack.append(ch)
		elif ch ==')':
			if len(stack) == 0:
				return False
			if not stack.pop() == '(':
				return False

			
	return len(stack) == 0

print valid_parentheses("hi())(")