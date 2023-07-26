S = input()
end_set = []
for i in range(len(S)):
  end_set.append(S[i:])
end_set.sort()
for i in range(len(S)):
  print(end_set[i])