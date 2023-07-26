menuArr = []
bevArr = []
for i in range(5):
  if i<3:
    menuArr.append(int(input()))
  else:
    bevArr.append(int(input()))
menuArr.sort()
bevArr.sort()
print(menuArr[0]+bevArr[0]-50)