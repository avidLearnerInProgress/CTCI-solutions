#https://ide.geeksforgeeks.org/5TAL2ZXgXN
if __name__ == "__main__":
    a = str(input())
    b = str(input())
    if len(a) < 0 or len(b) < 0 or len(a) != len(b):
        print("b !substring of a")
    a += a
    if b in a: print("b is substring of a")
    else: print("b !substring of a")