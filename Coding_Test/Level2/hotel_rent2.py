def time2min(time):
    hour = int(time[:2])
    minute = int(time[3:])
    return hour * 60 + minute

def solution(book_time):
    answer = 0
    minute = [0 for _ in range(24*60 + 10)]

    print(minute)

    for book in book_time:
        start = time2min(book[0])
        end = time2min(book[1])
        minute[start] += 1
        minute[end+10] += -1
    num = 0
    for i in range(len(minute)):
        num += minute[i]
        minute[i] = num

    answer = max(minute)

    return answer

if __name__ == '__main__':
    book_time = [["10:20", "12:30"], ["10:20", "12:30"], ["10:20", "12:30"]]
    print(solution(book_time))