def anagram(str1, str2):
    n1 = len(str1)
    n2 = len(str2)

    if n1 != n2:
        return 0

    str1 = sorted(str1)
    str2 = sorted(str2)

    for i in range(0, n1):
        if str1[i] != str2[i]:
            return 0
    return 1


# Driver code
str1 = "listen"
str2 = "silent"

if anagram(str1, str2):
    print("Anagram")
else:
    print("Not Anagram")
