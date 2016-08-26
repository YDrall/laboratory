def prnt():
    print l, len(l)

l = list()
l.extend(range(10))

prnt()

l.append('abc')
prnt()

l.insert(0,'xyz')
prnt()

print l.index(4);

l.remove(4)
prnt()

l.pop()
prnt()

print sorted(l)

l[3]=9
prnt()

l2 = [34,34,54]

l += l2
prnt()

l += l2 * 3
prnt()

[x,y,z]=l2
print x, y, z


