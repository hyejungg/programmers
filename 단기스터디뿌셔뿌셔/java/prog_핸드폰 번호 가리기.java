class Solution {
    public String solution(String phone_number) {
        String answer = "";
        for(int i = 0; i < phone_number.length() - 4; i++)
            answer += '*';
        answer += phone_number.substring(phone_number.length() - 4);
        return answer;
    }
}

//미친 풀이~
class Solution {
    public String solution(String phone_number) {
        //전방탐색 (?=) : 다음에 오는 문자가 일치하는 영역에서 제외
        //임의의 글자 4개를 제외한 나머지를 *로 바꾸겠다.
        return phone_number.replaceAll(".(?=.{4})", "*");
    }
}