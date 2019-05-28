#https://ide.geeksforgeeks.org/FfcFvjeTeV

#using hashing
def unique_hashed(strr):
    if strr is None:
        return False
    hash_set = [0] * 128
    for char in strr:
        if hash_set[ord(char)] == True:
            return False
        else:
            hash_set[ord(char)] = True
    return True

def unique_sorted(strr):
    if strr is None:
        return False
    sorted_str = sorted(strr)
    for i in range(len(sorted_str) - 1):
        if sorted_str[i] == sorted_str[i + 1]:
            return False
    return True     

def unique_bit(strr):
    if strr is None:
        return False
    check = 0
    for char in strr:
        if (check & (1 << ord(char)) > 0):
            return False
        check = check | (1 << ord(char))
    return True

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        st = str(input())
        if unique_hashed(st):
            print("Is Unique")
        else:
            print("Not Unique")
        if unique_sorted(st):
            print("Is Unique")
        else:
            print("Not Unique")
        if unique_bit(st):
            print("Is Unique")
        else:
            print("Not Unique")
        tc -= 1