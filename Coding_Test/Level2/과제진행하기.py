def getStarttime(e: list):
    return e[1]

def solution(plans : list):
    plans.sort(key = getStarttime)

    print(plans)
    
    answer = []
    hold = []
    for i in range(0, len(plans)):
        hour = int(plans[i][1][0:2])
        min = int(plans[i][1][3:5])
        total = hour*60 + min
        
        if i != len(plans)-1:
            hour2 = int(plans[i+1][1][0:2])
            min2 = int(plans[i+1][1][3:5])
            total2 = hour2*60 + min2
        else:
            answer.append(plans[i][0])
            for h in reversed(hold):
                answer.append(h[0])
            break
                
        
        left = total2 - total
        playtime = int(plans[i][2])
        
        if left - playtime < 0:
            tmp = [plans[i][0], playtime - left]
            hold.append(tmp)
        else:
            answer.append(plans[i][0])
            
            if left - playtime > 0:
                left -= playtime          
                while len(hold) > 0:
                    if left - hold[-1][1] >= 0:
                        answer.append(hold[-1][0])
                        left -= hold[-1][1]
                        hold.pop()
                    else:
                        hold[-1][1] -= left
                        break
    return answer


if __name__ == '__main__':
    plans =  [["1", "00:00", "30"], ["2", "00:10", "10"], ["3", "00:30", "10"], ["4", "00:50", "10"]] 
    answer = solution(plans)
    print(answer)