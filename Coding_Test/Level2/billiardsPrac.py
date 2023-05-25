def solution(m, n, startX, startY, balls):
    answer = []

    a = [-startX, startY]
    b = [startX, -startY]
    c = [m+startX, startY]
    d = [startX, n+startY]

    for ball in balls:
        tmp = []
        aLen = (ball[0]-a[0]) * (ball[0]-a[0]) + (ball[1]-a[1])*(ball[1]-a[1])
        bLen = (ball[0]-a[0]) * (ball[0]-a[0]) + (ball[1]-a[1])*(ball[1]-a[1])
        cLen = (ball[0]-a[0]) * (ball[0]-a[0]) + (ball[1]-a[1])*(ball[1]-a[1])
        dLen = (ball[0]-a[0]) * (ball[0]-a[0]) + (ball[1]-a[1])*(ball[1]-a[1])
        tmp.append(aLen)
        tmp.append(bLen)
        tmp.append(cLen)
        tmp.append(dLen)
        answer.append(min(tmp))

    return answer



if __name__ == '__main__':
    m = 10
    n = 10
    startX = 3
    startY = 7
    balls = [[7, 7], [2, 7], [7, 3]]
    result = solution(m,n,startX, startY, balls)
    print(result)