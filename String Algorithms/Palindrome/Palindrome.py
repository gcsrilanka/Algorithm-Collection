def palindrome(str1):
    str2 = str1[::-1]

    if str1 == str2:
        return True

# Driver code
str1 = "racecar"

if palindrome(str1):
    print("Palindrome")
else:
    print("Not Palindrome")
