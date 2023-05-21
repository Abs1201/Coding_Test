import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.ArrayList;

class Solution {
    public int[] convertTime(String[][] plan) {
        int[] result = new int[plan.length];
        
        for(int i = 0; i < plan.length; i++) {
            String[] temp = plan[i][1].split(":");
            result[i] = ((Integer.parseInt(temp[0]) * 60) + (Integer.parseInt(temp[1])));
        }
        
        return result;
    }
    
    public int findIndex(int[] array, int value) {
        for(int i = 0; i < array.length; i++)
        	if(array[i] == value)  
        		return i;
        
        return 0;
    }
    
    public String[] solution(String[][] plans) {
        int[] index = convertTime(plans);
        
        int[] sortIndex = index.clone();
        Arrays.sort(sortIndex);
        int[] leftTime = new int[plans.length];
        
        for(int i = 0; i < leftTime.length; i++) 
            leftTime[i] = Integer.parseInt(plans[findIndex(index, sortIndex[i])][2]);
        
        List<Integer> indexList = Arrays.stream(sortIndex).boxed().collect(Collectors.toList());
        List<Integer> leftList = Arrays.stream(leftTime).boxed().collect(Collectors.toList());
        List<String> result = new ArrayList<String>();
        
        
        for(int i = 0; i < indexList.size() - 1; i++) {
            int requireTime = indexList.get(i) + leftList.get(i);
            int tempTime = 0;
            if(requireTime < indexList.get(i + 1)) {
                if(i > 0) {
                    tempTime = indexList.get(i + 1) - requireTime;
                	result.add(plans[findIndex(index, indexList.get(i))][0]);
                    indexList.remove(i);
                    leftList.remove(i);
                    
                    while(tempTime > 0) {
                        if(i > 0) {
                            i -= 1;
                        }
                        
                        if(tempTime > leftList.get(i)) {
                            tempTime -= leftList.get(i);
                            result.add(plans[findIndex(index, indexList.get(i))][0]);
                            indexList.remove(i);
                            leftList.remove(i);
                            if(i == 0) {
                                i--;
                                tempTime = 0;
                            }
                        }
                        else if(tempTime == leftList.get(i)) {
                            tempTime = 0;
                            result.add(plans[findIndex(index, indexList.get(i))][0]);
                            indexList.remove(i);
                            leftList.remove(i);
                            i -= 1;
                        } 
                        else {
                            leftList.set(i, leftList.get(i) - tempTime);
                            tempTime = 0;
                        }
                    }
                }
                else {
                    result.add(plans[findIndex(index, indexList.get(i))][0]);
                    indexList.remove(i);
                    leftList.remove(i);
                    i -= 1;
                }
            }
            else if(requireTime == indexList.get(i + 1)) {
                result.add(plans[findIndex(index, indexList.get(i))][0]);
                indexList.remove(i);
                leftList.remove(i);
                i -= 1;
            }
            else {
                leftList.set(i, leftList.get(i) - (indexList.get(i + 1) - indexList.get(i)));
            }
        }
        
        while(result.size() < plans.length) {
            if(indexList.size() > 0) {
                int last = indexList.size() - 1;
                result.add(plans[findIndex(index, indexList.get(last))][0]);
                indexList.remove(last);
                leftList.remove(last);
            }
        }
        
        return result.toArray(new String[result.size()]);
    }

    
}