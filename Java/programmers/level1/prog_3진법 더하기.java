import java.util.*;

class Solution {
    public int solution(int n) {int answer = 0;
        StringBuilder str = new StringBuilder();

        // 3진법 수 구해
        while(true){
            if(n / 3 == 0){
                str.append(n % 3);
                break;
            }
            str.append(n % 3);
            n /= 3;
        }

        // 10진법으로 표기
        int idx = 0;
        for(int i = str.length() - 1; i >= 0; i--) {
            answer += Integer.parseInt(String.valueOf(str.charAt(i))) * Math.pow(3, idx);
            idx++;
        }
        return answer;
    }
}