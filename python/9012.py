T = int(input())
for i in range(T):
  PS = input()
  index = 0
  code = 1
  for i in range(len(PS)):
    if PS[i]=="(":
      index += 1
    elif PS[i]==")":
      index -= 1
    if index<0:
      print("NO")
      code = 0
      break
  if code == 1 and index == 0:
    print("YES")
  elif code == 1:
    print("NO")