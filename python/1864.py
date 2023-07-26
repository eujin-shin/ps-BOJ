octopus = "-\(@?>&%"
ansArr = []
while True:
  word = input()
  if(word=='#'):
    break
  sum = 0
  for i in range(len(word)):
    x = octopus.find(word[i])
    sum += (8**(len(word)-i-1))*x
  ansArr.append(sum)
for i in ansArr:
  print(i)