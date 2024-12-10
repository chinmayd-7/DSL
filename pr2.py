def get_marks(N):
    marks=[]
    for i in range(N):
        print("Enter marks of student",i+1,"Enter -1 if absent")
        mark=int(input())
        marks.append(mark)
    return marks

def calculate_average(marks):
    sum=0
    count=0
    for i in range(len(marks)):
        if(marks[i]==-1):
            continue
        sum+=int(marks[i])
        count+=1
    return sum/count

def find_maximum(marks):
    max=marks[0]
    for i in range(len(marks)):
        if(marks[i]==-1):
            continue
        if(max<int(marks[i])):
            max=marks[i]
    return max

def find_minimum(marks):
    min=marks[0]
    for i in range(len(marks)):
        if(marks[i]==-1):
            continue
        if(min>int(marks[i])):
            min=marks[i]
    return min

def get_absent_students(marks):
    absents=[]
    for i in range(len(marks)):
        if(marks[i]==-1):
            ele="Student "+str(i+1)
            absents.append(ele)
    return absents

def highest_freq(marks):
    high_freq=marks[0]
    freq=0
    for i in range(len(marks)):
        if(marks[i]==-1):
            continue
        if(marks.count(i)>freq):
            freq=marks.count(i)
            high_freq=i
            
        #without count()
        # curr=marks[i]
        # count=0
        # for j in range(len(marks)):
        #     if(marks[j]==-1):
        #         continue
        #     if(curr==marks[j]):
        #         count+=1
        # if(count>freq):
        #     freq=count
        #     high_freq=curr
    return high_freq


N=int(input("Enter no. of students"))
marks=get_marks(N)
    
if len(marks)>0:
        average=calculate_average(marks)
        maximum=find_maximum(marks)
        minimum=find_minimum(marks)
        absents=get_absent_students(marks)
        
        print("Average marks:",average)
        print("Maximum marks:",maximum)
        print("Minimum marks:",minimum)
        print("Absent students:",absents)
        print("marks with highest frequency:",highest_freq(marks))

