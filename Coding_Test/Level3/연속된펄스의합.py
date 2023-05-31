def solution(sequence):
    answer = 0
    arr1 = []
    arr2 = []
    for i in range(len(sequence)):
        if i % 2 == 0:
            arr1.append(sequence[i])
            arr2.append(-sequence[i])
        else:
            arr1.append(-sequence[i])
            arr2.append(sequence[i])
            
    m1 = getMax(arr1)
    m2 = getMax(arr2)
    
    return max(m1,m2)
                 
def getMax(arr: list):
    big = 0
    tmp = 0
    if arr[0] > 0:
        big = arr[0]
        tmp = big
    for i in range(1, len(arr)):
        if arr[i] > 0:
            tmp = tmp + arr[i]
            big = max(big, tmp)
        else:
            if tmp + arr[i] <= 0:
                tmp = 0
            else:
                tmp = tmp + arr[i]
                
    return big

if __name__=='__main__':
    sequence = [2, 3, -6, 1, 3, -1, 2, 4]
    answer = solution(sequence)
    print(answer)
