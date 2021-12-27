from cs50 import get_string

# propt user for text
text = get_string("Text: ")

wordcount = 1
sentences = 0
lettercount = 0

# count letters, words, and sentences
for c in text:
    if c == " ":
        wordcount += 1
    elif c == "." or c == "?" or c == "!":
        sentences += 1
    elif c.isalpha():
        lettercount += 1

# calculate difficulty: index = 0.0588 * L - 0.296 * S - 15.8
# L is the average amount of letters per 100 words
# S average amount of sentences per 100 words
L = 100 * lettercount / wordcount
S = 100 * sentences / wordcount
index = 0.0588 * L - 0.296 * S - 15.8
grade = round(index)

# output grade
if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {grade}")