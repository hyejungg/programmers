class Solution {
    public int solution(int n) {
        int idx = 2;
        while(!(n % idx == 1)) {
            ++idx;
        }
        return idx;
    }
}

import java.util.*;
import java.util.stream.IntStream;

// stream은 함수비용이 적은 코드에서는 성능이 좋지 않음
class Solution {
    public int solution(int n) {
        return IntStream.range(2, n).filter(idx -> n % idx == 1).findFirst().orElse(0);
    }
}