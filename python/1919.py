word_a = list(input())
word_b = list(input())
intersection = [x for x in word_a if x in word_b]
del_a = list(set(word_a) - set(intersection))
del_b = list(set(word_b) - set(intersection))
print(del_a)
print(len(del_a)+len(del_b))