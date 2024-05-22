from collections import deque

q1 = deque()
q2 = deque()

q1.append(1)
q1.append(3)
q1.append(7)

for i in range(4, 7):
    q1.append(i)  # Pushing 4, 5, 6

# Total 6 elements in q1: Order of push: 1 3 7 4 5 6

while q1:
    temp = q1[0]
    print(temp, end=" ")
    q1.popleft()
print()

q2.append("sagar")
q2.append("vishnu")
q2.append("shreya")

while q2:
    temp = q2[0]
    print(temp, end=" ")
    q2.popleft()
print()
