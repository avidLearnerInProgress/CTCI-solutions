

#https://ide.geeksforgeeks.org/0sYLKxGN46
def urlify(mystr, length):
    if mystr is None or mystr is "" or len is None:
        return None
        
    url = []
    for i in range(length):
        if mystr[i] == " ":
            url.append("%20")
        else:
            url.append(mystr[i])
    return ''.join(url)
    
if __name__ == "__main__":
    catch = urlify("Mr John Smith    ", 13)
    if catch is not None: 
        print(catch)
    else:
        print("Invalid string literal")