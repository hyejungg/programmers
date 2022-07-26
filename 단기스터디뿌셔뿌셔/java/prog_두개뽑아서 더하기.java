import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        Set<Integer> set = new TreeSet<Integer>(); //오름차순 정렬 set 생성(중복허용x)
        Arrays.sort(numbers); //오름차순 정렬
        
        for(int i = 0; i < numbers.length; i++){
            for(int j = i + 1; j < numbers.length; j++){
                set.add(numbers[i] + numbers[j]);
            }
        }
        // Set -> 배열 
        return set.stream().mapToInt(Integer::intValue).toArray();
    }
}