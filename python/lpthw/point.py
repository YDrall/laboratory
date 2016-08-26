# An example of class in python.

class Point:
    "Point class for storing mathematical points."
    def __init__(self,x=0,y=0):
        self.x = x
        self.y = y
    
    def distance_from_origin(self):
        return ((self.x **2) + (self.y **2)) **0.5


if __name__ == "__main__":
    from sys import argv
    if len(argv) != 3:
            print "usage: %s x_cordinate y_cordinate " %(argv[0])

    else:
        p = Point(int(argv[1]), int(argv[2]) )
        print p.distance_from_origin()

