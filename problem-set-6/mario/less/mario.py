from cs50 import get_int

# Get height from user
height = get_int("Height: ")

# Check for valid height
while (True):
    if (height > 8 or height < 1):
        height = get_int("Height: ")
    else:
        break

# Print pyramid
for i in range(height):
    print((height - 1 - i) * " ", end="")
    print((1 + i) * "#")
