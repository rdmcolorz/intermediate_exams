def is_anagram(strA, strB):
    countA = 0
    countB = 0
    for ele in strA:
        countA += ord(ele)
    for ele in strB:
        countB += ord(ele)
    if countA == countB:
        return 1
    else:
        return 0

print(is_anagram('hello', 'ello1h'))