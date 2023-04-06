
def solution(n:int, words:list):
    index = 0
    answer = []
    for w in words:
        tmp = []
        if w in tmp:
            answer.append(index % n + 1)
            answer.append(index / n + 1)        
            return answer
        tmp.append(w)
        index += 1
        print(tmp)
    return [0,0]


    

if __name__ == '__main__':
    n = 3
    words = ["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"]
    answer = solution(n,words)
    print(answer)
    print(words)