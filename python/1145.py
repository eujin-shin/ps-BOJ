num_list = list(map(int, input().split()))
num_list.sort()
max = num_list[0]*num_list[1]*num_list[2]
ans = 0
for i in range(1, max):
  count = 0
  for j in range(5):
    if i % num_list[j] == 0:
      count += 1
    if count >= 3:
      ans = i
      break
  if ans == i:
    break
if ans==0:
  print(max)
else:
  print(ans)