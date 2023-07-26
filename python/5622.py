num = input()
alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
time = 0
for i in range(len(num)):
  x = alp.index(num[i])
  if x<=2:
    time += 3
  elif x<=5:
    time += 4
  elif x<=8:
    time += 5
  elif x<=11:
    time += 6
  elif x<=14:
    time += 7
  elif x<=18:
    time += 8
  elif x<=21:
    time += 9
  else:
    time += 10
print(time)