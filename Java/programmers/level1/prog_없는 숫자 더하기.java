class Solution {
    public int solution(int[] numbers) {
        int answer = 45;
        for(int i = 0; i < numbers.length; i++){
            answer -= numbers[i];
        }
        return answer;
    }
}

//stream 이용
import java.util.*;

class Solution {
    public int solution(int[] numbers) {
        return 45 - Arrays.stream(numbers).sum(); 
    }
}