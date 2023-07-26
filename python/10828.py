n = int(input())
stack = []
for i in range(n):
  order = input()
  if "push" in order:
    if len(stack)==0:
      stack.append(order[5])
    else:
      stack.insert(0, order[5])
  elif "pop" in order:
    if len(stack)==0:
      print(-1)
    else: 
      print(stack[0])
      del stack[0]
  elif "size" in order:
    print(len(stack))
  elif "empty" in order:
    if len(stack)==0:
      print(1)
    else:
      print(0)
  elif "top" in order:
    if len(stack)==0:
      print(-1)
    else:
      print(stack[0])

