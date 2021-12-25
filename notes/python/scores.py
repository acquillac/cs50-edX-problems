# # python list
# scores = [24,44,46]

# print("Average: " + str(sum(scores) / len(scores)))
# print(f"Average: {str(sum(scores) / len(scores))}")

from cs50 import get_int

scores = []
for i in range(3):
    scores.append(get_int("Scores: "))

avg = sum(scores) / len(scores)
print(f"Average: {avg}")