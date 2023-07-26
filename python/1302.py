N = int(input())
book_list = []
num_list = []
ans_list = []
max = 1
for i in range(N):
  word = input()
  if word in book_list:
    k = book_list.index(word)
    num_list[k] += 1
    if num_list[k] > max:
      max = num_list[k]
  else:
    book_list.append(word)
    num_list.append(1)
for i in range(len(num_list)):
  if num_list[i] == max:
    ans_list.append(book_list[i])
ans_list.sort()
print(ans_list[0])
