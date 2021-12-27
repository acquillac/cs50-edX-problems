from cs50 import get_float

# Prompt user for change owed
change_owed = get_float("Change owed: ")

# Checking that change is greater than 1 cent
while True:
    if change_owed > 0.009:
        break
    else:
        change_owed = get_float("Change owed: ")

# Rounding change
change_rounded = round(change_owed * 100)

# Counting coins needed for change
coins = 0

# Cointing coins
while change_rounded > 0:

    # Quarter
    q = int(change_rounded / 25)
    q_amount = q * 25
    change_rounded = change_rounded - q_amount
    coins = q
    if change_rounded == 0:
        break

    # Dime
    d = int(change_rounded / 10)
    d_amount = d * 10
    change_rounded = change_rounded - d_amount
    coins = q + d
    if change_rounded == 0:
        break

    # Nickel
    n = int(change_rounded / 5)
    n_amount = n * 5
    change_rounded = change_rounded - n_amount
    coins = q + d + n
    if change_rounded == 0:
        break

    # Penny
    p = int(change_rounded / 1)
    p_amount = p * 1
    change_rounded = change_rounded - p_amount
    coins = q + d + n + p
    if change_rounded == 0:
        break


print(coins)

