# BOJ-03613 / Java vs C++
# devgeon, 2023.01.11, Python3
# https://www.acmicpc.net/problem/3613

def to_java_style(original):
    i = 0
    translated = ""
    while i < len(original):
        if original[i] == "_":
            i += 1
            translated += original[i].upper()
        else:
            translated += original[i]
        i += 1
    return translated

def to_cpp_style(origianl):
    translated = ""
    for c in origianl:
        if c.isupper():
            translated += "_" + c.lower()
        else:
            translated += c
    return translated

def main():
    original = input()
    translated = "Error!"

    if original[0].isupper()\
    or "_" in [original[0], original[-1]]\
    or "__" in original:
        pass
    elif "_" not in original:
        translated = to_cpp_style(original)
    elif original.islower():
        translated = to_java_style(original)
    
    print(translated)

if __name__ == "__main__":
    main()
