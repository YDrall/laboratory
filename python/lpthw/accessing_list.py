
list = [1, "dj", 4, "dkf", 3, 5 ,2]

def getItem(list, index):
    if(index < len(list)):
        return list[index]
    else:
        return "index out of bound"

if __name__ == "__main__":
    while(True):
        n = int(raw_input("Enter index: "))
        print getItem(list,n)

