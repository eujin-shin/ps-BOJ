num_list = list(map(int, input().split()))
sorted_list = sorted(num_list)
reversed_list = sorted(num_list, reverse=True)
if num_list == sorted_list:
  print("ascending")
elif num_list == reversed_list:
  print("descending")
else:
  print("mixed")