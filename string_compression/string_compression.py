def string_compression(x):
    if len(x) < 1:
        return ""
    count_compression = 0
    result = ""
    for i in range(len(x)):
        count_compression += 1
        if i + 1 >= len(x) or x[i] != x[i+1]:
            result += x[i]
            result += str(count_compression)
            count_compression = 0
    if len(result) < len(x):
        return result
    else:
        return x

def lookaheadCount(x):
    count_compression = 0
    final_count = 0
    for i in range(len(x)):
        count_compression += 1
        if i + 1 >= len(x) or x[i] != x[i+1]:
            final_count += count_compression
            count_compression = 0
    return final_count

def lookahead_compression(x):
    if len(x) < 1:
        return ""
    compressed_count = lookaheadCount(x)
    if compressed_count > len(x): 
        return x
    count_compression = 0
    result = ""
    for i in range(len(x)):
        count_compression += 1
        if i + 1 >= len(x) or x[i] != x[i+1]:
            result += x[i]
            result += str(count_compression)
            count_compression = 0
    return result

if __name__ == "__main__":
    print(string_compression("aaabbccddeeff"))
    print(lookahead_compression("aaabbccddeeff"))