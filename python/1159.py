N = int(input())
firstnames = []
firstname = []
answer = []
for i in range(N):
  name = input()
  firstnames.append(name[0])
  if not(name[0] in firstname):
    firstname.append(name[0])
for i in range(len(firstname)):
  x = firstname[i]
  count = 0
  for j in range(len(firstnames)):
    if firstnames[j]==x:
      count += 1
  if count>4:
    answer.append(x)
if len(answer)==0:
  print("PREDAJA")
else:
  answer.sort()
  print(''.join(answer))