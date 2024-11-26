def fat(x):
    if x <= 2:
        return x
    return x * fat(x-1)

print(fat(1000))