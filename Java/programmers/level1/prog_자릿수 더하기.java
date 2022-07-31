import java.util.*;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        while(n != 0){
            answer += (n % 10);
            n /= 10;
        }
        return answer;
    }
}

// c++ 처럼 풀기 (전자 방법보다 리소스를 많이 잡아먹는다고 함)
import java.util.*;

public class Solution {
    public int solution(int n) {
        int answer = 0;

        String nStr = String.valueOf(n); //int -> String 할 땐 String.valueOf()
        for(int i = 0; i < nStr.length(); i++){ //String의 길이는 size()가 아닌 length()로
	        int num = nStr.charAt(i)-'0'; //char -> int 로 변환 시, .charAt(idx) - '0'. '0'을 안빼면 아스키코드로 변환됨
            answer += num;
        }

        return answer;
    }
}