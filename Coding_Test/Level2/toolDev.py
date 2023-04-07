import math

def solution(progresses, speeds):
    answer = []

    tmp = [] # 7,70,45
    tmp2 = []
    count = 0
    maxDay = max()
    for p in progresses:
        tmp.append(100-p)
    for i in range(0, len(speeds)):
        tmp2.append(math.ceil(tmp[i]/speeds[i]))
    for t in tmp2:
        if maxDay >= t:
            count += 1
            maxDay = t
        else:
            answer.append(count)


    return answer

if __name__ == '__main__':
    progresses = [93, 30, 55]
    speeds = [1, 30, 5]
    answer = solution(progresses, speeds)
    print(answer)


