def set_bit(x, position):
    mask = 1 << position
    return x | mask

def clear_bit(x, position):
    mask = 1 << position
    return x & (~mask)

def flip_bit(x ,position):
    mask = 1 << position
    return x ^ mask

def is_bit_set(x ,position):
    shiftedx = x >> position
    return (shiftedx & 1) == 1

def modify_bit(x, position, state):
    mask = x << position
    return (x & ~mask) | (-state & mask)

def is_even(x):
    return (x&1) == 0

def is_power_of_two(x):
    return (x & (x-1)) ==0

def count_bit(x):
    count =0
    while(x>0):
        count += x&1
        x = x>>1
    return count

def count_bit_fast(x):
    count =0
    while(x):
        x = x&(x-1)
        count +=1
    return count

def bits_diffs_count(x,y):
    return count_bit(x^y)

