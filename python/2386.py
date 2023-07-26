ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
alphabet = "abcdefghijklmnopqrstuvwxyz"
ansArr = []
while True:
  sentence = input()
  if sentence == "#":
    break
  small_letter = sentence[0]
  a = alphabet.index(small_letter)
  big_letter = ALPHABET[a]
  small_count = sentence.count(small_letter)
  big_count = sentence.count(big_letter)
  print(small_letter, small_count+big_count-1)