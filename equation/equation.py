def equation(nb):
    a = 0
    while (a < 10):
        b = 0
        while (b < 10):
            c = 0
            while (c < 10):
                if (a * 10 + b + c * 10 + a == nb):
                    print("A = %i, B = %i, C = %i" %(a, b, c))
                c += 1
            b += 1
        a += 1

equation(42)