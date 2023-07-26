n = int(input())
enter = []
leave = []
for i in range(n):
  name, stat = input().split()
  if stat == "leave":
    leave.append(name)
  elif stat == "enter":
    enter.append(name)
enter.sort(reverse=True)
leave.sort(reverse=True)

k=0
for i in range(len(enter)):
  if(len(leave)>k and leave[k] == enter[i]):
    k+=1
  else:
    print(enter[i])
