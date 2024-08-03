def func(lst):
    total = 0
    for i in range(len(lst)):
        if i % 2 == 0:
            total += lst[i]
        else:
            total -= lst[i]
    return total

input_string = input()
lst = list(map(int, input_string.split()))

print(func(lst))
