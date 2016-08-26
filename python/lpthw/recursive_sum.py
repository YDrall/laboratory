
def r_sum(num_list):
    sum = 0;
    for element in num_list:
        if type(element) is type([]):
            sum = sum + r_sum(element)
        else:      
            sum = sum + element
    return sum


