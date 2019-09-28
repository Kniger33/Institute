def PrintList(l: list):
    for v in l:
        print(v)

def AddElement(l: list):
    newValue = input("New value: ")
    try:
        l.insert(0, int(newValue))
        return True
    except ValueError:
        pass

    try:
        l.insert(0, float(newValue))
        return True
    except ValueError:
        pass

    l.insert(0, newValue)
    return True

def DeleteFirst(l: list):
    l.pop(0)

def Task4(l: list):
    t = []
    for v in l:
        if type(v) == float and v > 100.0:
            t.append(v)

    myTuple = tuple(t)
    print(myTuple)

def SumIntNegative(l: list):
    sum = 0
    for v in l:
        if type(v) == int and v < 0:
            sum += v
    print("Sum: " + str(sum))

def NumbersCount(l: list):
    s = str(l)
    count = [int(i) for i in s if i.isdigit()]

    print("Count: " + str(len(count)))

def CreateM(l: list):

    print("Enter set elements:")

    custom_set = set(map(str, input().split()))
    print(str(custom_set))
    list_set = set(map(str, l))
    print(list_set.difference(custom_set))

def CreateDictionary(l: list):
    myDict = {}

    for i, v in enumerate(l):
        myDict[i] = v
    for i, v in myDict.items():
        print(v) if i % 2 == 0 else 0

def TaskTwoMain():
    custom_list = [-1, 153.5, "Python", -14, 17, -5, 147.4, "Hello"]

    while True:
        print("1 - Show list")
        print("2 - Add new element")
        print("3 - Delete first element")
        print("4 - Show element > 100")
        print("5 - Sum all int negative element")
        print("6 - Count of numbers in string of list")
        print("7 - Create M1")
        print("8 - Show dictionary")
        print("0 - Exit")
        command = input("Command:")

        if command == '1':
            PrintList(custom_list)
        elif command == '2':
            AddElement(custom_list)
        elif command == '3':
            DeleteFirst(custom_list)
        elif command == '4':
            Task4(custom_list)
        elif command == '5':
            SumIntNegative(custom_list)
        elif command == '6':
            NumbersCount(custom_list)
        elif command == '7':
            CreateM(custom_list)
        elif command == "8":
            CreateDictionary(custom_list)
        elif command == '0':
            return
        else:
            print("Incorrect command")
