def solution(people : list, limit : int):
    answer = 0
    people.sort(reverse=True)
    while(len(people) > 0):
        lim = limit
        lim -= people[0]
        del people[0]
        while len(people) > 0 and people[-1] <= lim:
            lim -= people[-1]
            del people[-1]
        answer += 1
    return answer



def sort1(array : list, reverse = False):
    if reverse == True:
        return 1
    else:
        return 2
        
        

if __name__ == "__main__":
    people = [50,70,40]
    limit = 100
    print(solution(people, limit))