while True:
    x = float(input("Enter X:"))

    if abs(x) < 1 or abs(x) > 3: break

    summ = 0
    d = 1

    for i in range(15):
        summ += 1 / (d * pow(x, d))
        d += 2

    print("Row sum: " + str(summ))
