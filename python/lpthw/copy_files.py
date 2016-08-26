from sys import argv
from os.path import exists

script, from_file, tofile = argv

print "Copying from %s to %s." % (from_file, tofile)

indata = open(from_file).read()
print "The input file is %d bytes long"% len(indata)

if exists(tofile) is False:
    print "Output file doesn't exists, so creating a new output file."

out_file = open(tofile,'w')
out_file.write(indata)

print "Alright all done"

out_file.close();



