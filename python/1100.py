ans = 0
for i in range(1,9):
  line = input()
  if i%2==0:
    for k in range(1, 5):
      if line[k*2-1]=="F":
        ans = ans+1
  else:
    for k in range(0, 4):
      if line[k*2]=="F":
        ans = ans+1
print(ans)