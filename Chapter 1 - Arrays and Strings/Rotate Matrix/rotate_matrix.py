#https://ide.geeksforgeeks.org/mmXcbJQgMV
def print_mat(cp_my_ip):
    for i in range(len(cp_my_ip)):
        for j in range(len(cp_my_ip[0])):
            print(cp_my_ip[i][j], end = ' ')
        print()

def rotate_matrix(cp_my_ip):
    n = len(cp_my_ip)
    level, first, last = 0, 0, 0
    for level in range(n//2): #n/2 --> for 4x4 cp_my_ip, it will have 2 layers
        first = level
        last = n - first - 1
        for element in range(first, last):
            offset = element - first
            topleft = cp_my_ip[first][element]
            topright = cp_my_ip[element][last]
            bottomright = cp_my_ip[last][last - offset]
            bottomleft = cp_my_ip[last - offset][first]
            cp_my_ip[first][element] = bottomleft
            cp_my_ip[element][last] = topleft
            cp_my_ip[last][last - offset] = topright
            cp_my_ip[last - offset][first] = bottomright
            #shifting the col value to its pos, since its a clockwise rotation so, seven will be at 1
    print_mat(cp_my_ip)

if __name__ == "__main__":
    rotate_matrix([[1,2,3],[4,5,6],[7,8,9]])