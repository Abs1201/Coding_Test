
def solution(n:int, words:list):
    index = 0
    answer = []
    tmp = []
    for w in words:
        if w in tmp:
            answer.append(index % n + 1)
            answer.append(index // n + 1)        
            return answer
        if index > 0 and w[0] != tmp[-1][-1]:
            answer.append(index % n + 1)
            answer.append(index // n + 1)        
            return answer
        
        tmp.append(w)
        index += 1
    return [0,0]


    

if __name__ == '__main__':
    n = 2
    words = ["hello", "one", "even", "never", "now", "world", "draw"]
    answer = solution(n,words)
    print(answer)