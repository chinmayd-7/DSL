"""Write a Python program to compute following operations on String:

a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
"""

str=input("Enter string:")
split_str=str.split()

#To display word with the longest length
def longest_word():
    longest=""
    max=0
    for i in split_str:
        if max<len(i):
            max=len(i)
            longest=i
    return longest

#To determines the frequency of occurrence of particular character in the string
def frequency(ch):
    count=0
    for i in str:
        if i==ch:
            count+=1
    return count

#To check whether given string is palindrome or not
def palindrome():
    str1=str.replace(" ","")
    i=0
    flag=1
    j=len(str1)-1
    while(i<j):
        if(str1[i]!=str1[j]):
            flag=0
            break
        else:
            i+=1
            j-=1
    if flag==0:
        print("Not palindrome")
    else:
        print("Palindrome")

#To display index of first appearance of the substring
def first_occuerence(substr):
    cnt=0
    for i in range(len(str)-len(substr)+1):
        if str[i:i+len(substr)]==substr:
            print(i) 
            return
    print("substring not found")

#To count the occurrences of each word in a given string
def occurence_word():
    count=0
    for i in split_str:
        for j in split_str:
            if i==j:
                count+=1
        print(i,":",count) 
        count=0

print("longest word:",longest_word())

ch=input("Enter character to count its occurences:")
print("occuences of ",ch,": ",frequency(ch))

palindrome()

substr=input("Enter substring to find first ocuurence:")
first_occuerence(substr)

print("Occurences of each word:")
occurence_word()