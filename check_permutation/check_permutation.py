#https://ide.geeksforgeeks.org/TXQ7H3pQ7B

def check_permutation_hashed(a, b):
    if len(a) != len(b):
        return False

    checker = [0] * (128)
    for char in a:
        checker[ord(char)] += 1

    for char_ in b:
        if checker[ord(char_)] == 0:
            return False
        checker[ord(char)] -= 1    
    return True

def check_permutation_sorted(a, b):
    if len(a) != len(b):
        return False
        
    sorted_a, sorted_b = sorted(a), sorted(b)
    for i in range(len(sorted_a)):
        if sorted_a[i] != sorted_b[i]:
            return False
    return True
    
if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        s = input().split(" ")
        print(s[0], s[1])
        if check_permutation_hashed(s[0], s[1]):
            print("Yes, equal")
        else:
            print("No, not equal")
        
        if check_permutation_sorted(s[0], s[1]):
            print("Yes, equal")
        else:
            print("No, not equal")
        tc -= 1