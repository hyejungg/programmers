import java.util.*;

class Solution {
    public int solution(int left, int right) {
        int answer = 0;
        for(int i = left; i <= right; i++){
            int divisor = getDivisor(i);
            
            if (divisor % 2 == 0) {
                answer += i;
            } else {
                answer -= i;
            }
        }
        return answer;
    }
    private int getDivisor(int num){
        ArrayList<Integer> nums = new ArrayList<>();
        for(int i = 1; i <= num; i++){
            if(num % i == 0)
                nums.add(i);
        }
        return nums.size();
    }
}