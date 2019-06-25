def sort_stack(s1):
    s2 = []
    while not s1 == []:
        current = s1.pop()
        while not s2 == [] and s2[-1] > current:
            s1.append(s2.pop())
        s2.append(current)
    return s2
print(sort_stack([10, 4, 3, 8, 2]))