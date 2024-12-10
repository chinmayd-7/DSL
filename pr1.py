print("Enter no. of students in class")
a=int(input())
U=[]
Cricket=[]
Badminton=[]
Football=[]
print("Enter roll no. of students in class")
for i in range(a):
    U.append(int(input()))
 
print("Enter no. of students who play cricket")
cric=int(input())
print("Enter roll no. of students who play cricket")
for i in range(cric):
    Cricket.append(int(input()))

print("Enter no. of students who play badminton")
badm=int(input())
print("Enter roll no. of students who play Badminton")
for i in range(badm):
    Badminton.append(int(input()))

print("Enter no. of students who play football")
foot=int(input())
print("Enter roll no. of students who play football")
for i in range(foot):
    Football.append(int(input()))

def inter_fun(A,B):
    for i in A:
        if i in B:
            print(i)

#optional
union_set=[]
def union_fun(A,B):
    for i in A:
        print(i)
        union_set.append(i)
    for i in B:
        if i not in A:
            print(i)
            union_set.append(i)
#optional
def diff_fun(A,B):
    for i in A:
        if i not in B:
            print(i)

def symm_diff(A,B):
    for i in A:
        if i not in B:
            print(i,end=',')
    for i in B:
        if i not in A:
            print(i,end=',')

def neither_A_nor_B(A,B):
    cnt=0
    for i in U:
        if i not in A and i not in B:
            cnt+=1
    print(cnt)

def A_and_B_not_C(A,B,C):
    cnt=0
    for i in A:
        if i in B and i not in C:
            cnt+=1
    print(cnt)

print("play both cricket and badminton")
inter_fun(Cricket,Badminton)
print()

print("students who play cricket or badminton but not both")
symm_diff(Cricket,Badminton)
print()

print("No. of students who play neither cricket not badminton")
neither_A_nor_B(Cricket,Badminton)
#can be also done by
# union_fun(Cricket,Badminton)
# diff_fun(U,union_set)

print("No. of students who play cricket and football but not badminton")
A_and_B_not_C(Cricket, Football,Badminton)

