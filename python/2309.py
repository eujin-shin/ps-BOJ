sum = 0
heightArr = []
for i in range(9):
  x = int(input())
  sum = sum + x
  heightArr.append(x)
num = sum - 100
for i in range(9):
  n = num-heightArr[i]
  if n in heightArr:
    indexN = heightArr.index(n)
    if indexN!=i:
      del heightArr[i]
      heightArr.remove(n)
      break
heightArr.sort()
for i in range(7):
  print(heightArr[i])