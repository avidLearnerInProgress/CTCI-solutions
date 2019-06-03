def oneAwayHashed(s1, s2):
    if abs(len(s1) - len(s2)) > 1:
        return False
    if len(s1) < 1 and len(s2) < 1:
        return False 
    
    if s1 > s2:
        s1, s2 = s1, s2
    else:
        s1, s2 = s2, s1

    hash_ = [0] * (256)

    for x in s1:
        hash_[ord(x)] += 1

    for x in s2:
        hash_[ord(x)] -= 1

    count_occr = 0
    for x in range(256):
        if hash_[x] > 0:
            count_occr += 1
    return count_occr <= 1 

def oneAway(s1, s2):
    if abs(len(s1) - len(s2)) > 1:
        return False
    if len(s1) < 1 and len(s2) < 1:
        return False
    
    if s1 > s2:
        s1, s2 = s1, s2
    else:
        s1, s2 = s2, s1

    m, n = len(s1), len(s2)
    _found = False
    i, j = 0, 0
    while i<m and j<n:
        if s1[i] != s2[j]:
            if _found == True:
                #print(s1[i], s2[j])
                return False
            _found = True
            if m == n:
                j += 1
                i += 1
        else:
            j += 1
            i += 1
    return True
        
if __name__ == "__main__":
    print(oneAwayHashed("bale", "pale"))
    print(oneAwayHashed("pale", "pal"))
    print(oneAwayHashed("bble", "xale"))
    print("#$#$#$#")
    print(oneAway("bale", "pale"))
    print(oneAway("pale", "pal"))
    print(oneAway("bble", "xale"))