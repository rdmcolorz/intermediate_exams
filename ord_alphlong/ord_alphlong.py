from __future__ import print_function
import sys

if len(sys.argv) != 2:
    print("")
else:
    sentence = sys.argv[1].split(" ")
    sentence = sorted(sentence, key=lambda s: s.lower())
    sentence.sort(key=len)
    max = 0
    i = 0
    count = len(sentence)
    while (i < count):
        print(sentence[i], end="")
        if i + 1 < count:
            if len(sentence[i]) == len(sentence[i+1]):
                print(" ", end="")
            else:
                print("")
        i += 1
    print('')