def maxSequence(arr):
	curr_max =0
	max_so_far = 0
	for a in arr:
		curr_max = max(0,a+curr_max)
		max_so_far = max(curr_max,max_so_far)
		print curr_max
		print max_so_far

	return max_so_far

print maxSequence([-2, 1, -3, 4, -1, 2, 1, -5, 4])