import math

def TaskOneMain():
    while True:
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

        while True:
            c = input("c = ")
            try:
                c = float(c)
            except ValueError:
                print("Its not float")
                continue
            break

        while True:
            n = input("n = ")
            try:
                n = float(n)
            except ValueError:
                print("Its not float")
                continue
            break

        while True:
            x = input("x = ")
            try:
                x = float(x)
            except ValueError:
                print("Its not float")
                continue
            break
        break

    calculate = lambda a, b, c, n, x: ((5 * math.pow(a, n * x))
                                       / math.fabs(b + c)) \
                                      - math.sqrt(math.fabs(math.sin(math.pow(x, n * x))))
    print("Result: " + str(calculate(a, b, c, n, x)))
    input("Press any key...")
