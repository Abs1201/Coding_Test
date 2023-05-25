# def isSameRatio(x,y,x1,y1):
#     if y*x1 == x*y1:
#         return True

# def isMatch(m, n, startX, startY, ball):
#     x = m-startX
#     y = n-startY
#     x1 = m-ball[0]
#     y1 = n-ball[1]
#     if y*x1 == x*y1:
#         return True
    
#     y = startY
#     y1 = ball[1]
#     if y*x1 == x*y1:
#         return True

#     x= startX
#     x1 = ball[0]
#     if y*x1 == x*y1:
#         return True
    
#     y = n-startY
#     y1 = n-ball[1]
#     if y*x1 == x*y1:
#         return True

#     return False

def isMatch(startX,startY,ball):
    if startX == ball[0] or startY == ball[1]:
        return True
    return False

def solution(m, n, startX, startY, balls):
    answer = []

    a = [-startX, startY]
    b = [startX, -startY]
    c = [(m-startX)+m, startY]
    d = [startX, (n-startY)+n]

    for ball in balls:
        if isMatch(m,n,startX,startY,ball):
            len = (startX-ball[0]) * (startX-ball[0]) + (startY-ball[1])*(startY-ball[1])
            answer.append(len)
            continue
        tmp = []
        aLen = (ball[0]-a[0]) * (ball[0]-a[0]) + (ball[1]-a[1])*(ball[1]-a[1])
        bLen = (ball[0]-b[0]) * (ball[0]-b[0]) + (ball[1]-b[1])*(ball[1]-b[1])
        cLen = (ball[0]-c[0]) * (ball[0]-c[0]) + (ball[1]-c[1])*(ball[1]-c[1])
        dLen = (ball[0]-d[0]) * (ball[0]-d[0]) + (ball[1]-d[1])*(ball[1]-d[1])
        tmp.append(aLen)
        tmp.append(bLen)
        tmp.append(cLen)
        tmp.append(dLen)
        print(tmp)
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