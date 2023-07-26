num_arr = [0, 1]

def GetPass(n):
  while len(num_arr)<=n:
    num_arr.append(num_arr[-1]*2+1)
  return num_arr[n]

ans_arr = []
T = int(input())

for i in range(T):
  n = int(input())
  ans_arr.append(GetPass(n))

for i in range(T):
  print(ans_arr[i])