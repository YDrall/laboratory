from sys import argv

script, imput_file = argv

def print_all(f):
    print f.read()

def rewind(f):
    f.seek(0)

def print_a_line(line_number, f):
    print line_number, f.readline()

current_file = open(imput_file)

print "first let print whole file"
print "-" *40
print_all(current_file)
print "-" *40

print "Ok lets rewind"
rewind(current_file)
print "*" *20

print "Now printing line by line"

current_line= 1
print_a_line(current_line, current_file)

current_line += 1
print_a_line(current_line, current_file)

current_line +=1
print_a_line(current_line, current_file)



