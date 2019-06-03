def getFrequency(x):
    ind = -1
    if x >= 'a' and x <= 'z':
        ind = x - 'a'
    if x >= 'A' and x <= 'Z':
        ind = x - 'A'
    return ind

def palindromePermutation(mystr):
    if len(mystr) < 1:
        return False
    hash_ = [0] * 26
    i, ctoi = 0, 0

    for i in range(len(mystr)):
        ctoi = getFrequency(str[i])
        if ctoi != -1:
            hash_[ord(ctoi)] += 1
    found_n = False    
    for i in range(27):
        if hash_[i] % 2 == 1 and found_n:
            return False
        if hash_[i] % 2 == 1 and (not found_n):
            found_n = True
    return found_n

def palindromePermutationCountOnGo(mystr):
    if len(mystr) < 1:
        return False
    _hash = [0] * 26
    i, ctoi, count_odd = 0
    
    for i in range(len(mystr)):
        ctoi = getFrequency(str[i])
        if ctoi != -1:
            _hash[ord(ctoi)] += 1
            if _hash[ord(ctoi)] % 2:
                count_odd += 1
            else:
                count_odd -= 1
    return count_odd<=1 

def toggle(ind, bit_vector):
    if ind < 0:
     return bit_vector;
    mask = 1 << ind
    #toggle
    if (mask & bit_vector) == 0:
        bit_vector = bit_vector | mask
    else:
        bit_vector = bit_vector & ~mask
    return bit_vector

def createBitVector(x):
    i, bit_vector = 0
    for i in range(len(x)):
        bit_vector = toggle(getFrequency(x[i]), bit_vector)
    return bit_vector

def checkOneSetBit(bit_vector):
    return ((bit_vector) & (bit_vector-1) == 0)

def palindromePermutationBit(x):
    if x.length() < 1:
        return False
    bit_vector = createBitVector(x)
    return bit_vector == 0 | checkOneSetBit(bit_vector)

if __name__ == "__main__":
    ip = "TACTD COA";
    if palindromePermutation(ip): print("Yes\n")
    else:
        print("No\n")
    if palindromePermutationCountOnGo(ip):
        print("Yes\n")
    else:
        print("No\n")
    if palindromePermutationBit(ip):
        print("Yes\n")
    else:
        print("No\n")