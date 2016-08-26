import itertools

# def same_structure_as(original,other):
# 	if type(original) != list and type(other) != list:
# 		return False
# 	if len(original) != len(other):
# 		return False
# 	for ch_original, ch_other in itertools.izip_longest(original,other):
# 		print ch_original,ch_other
# 		if check(ch_original,ch_other):
# 			return False
# 		elif type(ch_original) is list:
# 			if not same_structure_as(ch_original,ch_other):
# 				return False
# 	return True


def same_structure_as(original,other):
	print original,other
	if check(original,other):
		return False
	elif type(original) is list:
		for ch_original, ch_other in itertools.izip_longest(original,other):
			if not same_structure_as(ch_original,ch_other):
				return False
	elif original is None or other is None:
		return False
	return True


def check(item1, item2):
	return (type(item1) is list) ^ (type(item2) is list)

print same_structure_as([ 1, [ 1, 1 ] ], [ 2, [ 2 ] ] )
