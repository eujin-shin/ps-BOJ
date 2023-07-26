word = input()
index = 0
while index<len(word):
  print(word[index], end='')
  index += 1
  if index%10==0:
    print()
if index%10!=0:
  print()