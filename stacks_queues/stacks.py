s1 = []
s2 = []

s1.append(1)
s1.append(3)
s1.append(7)

for i in range(4, 7):
    s1.append(i)  # Pushing 4, 5, 6

# Total 6 elements in s1: Order of push: 1 3 7 4 5 6

while s1:
    temp = s1.pop()
    print(temp, end=" ")
print()

s2.append("sagar")
s2.append("vishnu")
s2.append("shreya")

while s2:
    temp = s2.pop()
    print(temp, end=" ")
print()
