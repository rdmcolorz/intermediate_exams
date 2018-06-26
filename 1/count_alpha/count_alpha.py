from __future__ import print_function
import sys

def isDup(word, word_len, j, i):
    while j >= 0:
        if word[j] == word[i]:
            return True
        j -= 1
    return False

def countLetter(word, word_len, i):
    count = 0
    word_len -= 1
    while word_len >= 0:
        if word[i] == word[word_len]:
            count += 1
        word_len -= 1
    return count

if len(sys.argv) != 2:
    print('\n')
else:
    word = sys.argv[1].lower()
    word_len = len(word)
    i = 0
    flag = 0
    while i < word_len:
        if (word[i].isalpha()):
            count = 0
            j = i - 1
            if (isDup(word, word_len, j, i) == False):
                count = countLetter(word, word_len, i)
                if flag == 1:
                    print(", ", end='')
                flag = 1
                print("%i%s" %(count, word[i]), end='')
                
        i += 1
    print('')