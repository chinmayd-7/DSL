print("Enter no. of students in class")
a=int(input())
U=[]
A=[]
B=[]
print("Enter roll no. of students in class")
for i in range(a):
    U.append(int(input()))
 
print("Enter no. of students who play cricket")
cric=int(input())
print("Enter roll no. of students who play cricket")
for i in range(cric):
    A.append(int(input()))

print("Enter no. of students who play badminton")
badm=int(input())
print("Enter roll no. of students who play Badminton")
for i in range(badm):
    B.append(int(input()))

union_set=[]
def union_fun(A,B):
    for i in A:
        print(i)
        union_set.append(i)
    for i in B:
        if i not in A:
            print(i)
            union_set.append(i)
    # print(union_set)
    # i=0
    # j=0
    # while(i<len(A) and j<len(B)):
    #     if(A[i]<B[j]):
    #         print(A[i],end=',')
    #         union_set.append(A[i])
    #         i+=1
    #     elif(A[i]>B[j]):
    #         print(B[j],end=',')
    #         union_set.append(B[j])
    #         j+=1
    #     else:
    #         print(A[i],end=',')
    #         union_set.append(A[i])
    #         i+=1
    #         j+=1
    # if(i==len(A)):
    #     while(j<len(B)):
    #         print(B[j],end=',')
    #         union_set.append(B[j])
    #         j+=1
    # elif(j==len(B)):
    #     while(i<len(A)):
    #         print(A[i],end=',')
    #         union_set.append(A[i])
    #         i+=1

def diff_fun(A,B):
    for i in A:
        if i not in B:
            print(i)
    # i=0
    # j=0
    # for i in range(len(A)):
    #     flag=1
    #     for j in range(len(B)):
    #         if (A[i]==B[j]):
    #             flag=0
    #     if flag==1:
    #         print(A[i],end=',')

def inter_fun(A,B):
    for i in A:
        if i in B:
            print(i)
    # i=0
    # j=0
    # while(i<len(A) and j<len(B)):
    #     if(A[i]<B[j]):
    #         # print(A[i],end=',')
    #         i+=1
    #     elif(A[i]>B[j]):
    #         # print(B[j],end=',')
    #         j+=1
    #     else:
    #         print(A[i],end=',')
    #         i+=1
    #         j+=1
print("Students who play either crickett or badminton or both:")
union_fun(A,B)
print()
print("Students who play only cricket:")
diff_fun(A,B)
print()
print("Students who play only badminton:")
diff_fun(B,A)
print()
print("Students who play both :")
inter_fun(B,A)
print()
print("Students who play both :")
inter_fun(B,A)
print()
print("Students who play NOthing :")
diff_fun(U,union_set)
print()