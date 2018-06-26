def count_of_2(nb):
    count = 0
    for i in xrange(nb + 1):
        while i > 0:
            if i % 10 == 2:
                count += 1
            i /= 10
    print count
    
count_of_2(12)