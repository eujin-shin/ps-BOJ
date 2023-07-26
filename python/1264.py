key = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
ansArr = []
while True:
  ans = 0
  sentence = input()
  if "#" in sentence:
    break
  for i in range(len(key)):
    ans += sentence.count(key[i])
  ansArr.append(ans)
for i in range(len(ansArr)):
  print(ansArr[i])
