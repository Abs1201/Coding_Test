
def getStartTime(e: list):
    return e[0]

def stoiTime(s: str):
    hour = int(s[0:2]) * 60
    min = int(s[3:5])
    
    return hour + min
    
def getSmallGapIndex(l : list):
    index = -1
    tmp = 1000000
    if len(l) > 0:
        if l[0] >= 0:
            index = 0
            tmp = l[0]
    for i in range(1, len(l)):
        if l[i] < tmp and l[i] >= 0:
            index = i
    return index

def solution(book_time):
    answer = 0
    lastBookTime = []
    
    book_time.sort(key=getStartTime)
    
    for bt in book_time:
        bt[0] = stoiTime(bt[0])
        bt[1] = stoiTime(bt[1])
    
    if len(book_time) > 0:
        lastBookTime.append(book_time[0][1])
        
    for i in range(1, len(book_time)):
        gap = []
        for lbt in lastBookTime:
            gap.append(book_time[i][0] - lbt - 10)
        index = getSmallGapIndex(gap)
        if index < 0:
            lastBookTime.append(book_time[i][1])
        else:
            lastBookTime[index] = book_time[i][1]
    
    answer = len(lastBookTime)
    
    return answer


if __name__ == '__main__':
    book_time = [["10:20", "12:30"], ["10:20", "12:30"], ["10:20", "12:30"]]
    answer = solution(book_time)
    print(answer)