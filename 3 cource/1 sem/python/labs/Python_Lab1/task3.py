import math

def Ellipse():
    res = 0.0

    while True:
        a = input("Big semiaxis = ")
        try:
            a = float(a)
        except ValueError:
            print("Its not float")
            continue
        break

    while True:
        b = input("Little semiaxis = ")
        try:
            b = float(b)
        except ValueError:
            print("Its not float")
            continue
        break

    res = math.pi * a * b
    print("Res: " + str(res))
    input()
    pass

def Triangle():
    res = 0.0

    while True:
        a = input("Basis of triangle = ")
        try:
            a = float(a)
        except ValueError:
            print("Its not float")
            continue
        break

    while True:
        h = input("Height = ")
        try:
            h = float(h)
        except ValueError:
            print("Its not float")
            continue
        break

    res = 1/2 * a * h
    print("Res: " + str(res))
    input()

def Rectangle():
    res = 0.0

    while True:
        a = input("a = ")
        try:
            a = float(a)
        except ValueError:
            print("Its not float")
            continue
        break

    while True:
        b = input("b = ")
        try:
            b = float(b)
        except ValueError:
            print("Its not float")
            continue
        break

    res = a * b
    print("Area: " + str(res))
    input()

def TaskThreeMain():
    while True:
        print("Ellipse - e")
        print("Triangle - t")
        print("Rectangle - r")
        print("Quit - q")
        command = input("Command:")

        if command == 'e':
            Ellipse()
        elif command == 't':
            Triangle()
        elif command == 'r':
            Rectangle()
        elif command == 'q':
            break
        else:
            print("Undefined command...")