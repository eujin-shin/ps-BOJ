n, p = map(int, input().split())
num_arr = list(map(int, input().split()))
num_arr = list(map(lambda num : num - n*p, num_arr))
for num in num_arr:
  print(num, end=' ')
print()