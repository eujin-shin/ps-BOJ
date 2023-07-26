n = int(input())
numSet = []
ansSet = []
k = 0
for i in range(n):
  numSet.append(i+1)
for i in range(n):  
  ansSet.append(numSet[k])
  numSet.remove(numSet[k])
  if len(numSet)==1:
    ansSet.append(numSet[0])
    break
  elif len(numSet)==0:
    break
  elif len(numSet)==k+1:
    k=0
  elif len(numSet)==k:
    k=1
  else:
    k=k+1
print(' '.join(str(x) for x in ansSet))