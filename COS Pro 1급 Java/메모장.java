// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Solution {
    public int solution(int K, String[] words) {
        // 여기에 코드를 작성해주세요.
        int answer = 1;
        String temp = "";
        
        for (String word : words) {
            if (temp.equals("")) {
                temp = word;
            } else if (temp.length() + word.length() + 1 > K) {
                temp = word;
                answer++;
            } else {
                temp += "_" + word;
            }
        }
        
        return answer;
    }

    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void main(String[] args) {
        Solution sol = new Solution();
        int K = 30;
        String[] words = {new String("nice"), new String("happy"), new String("nice"), new String("happy"), new String("nice"), new String("happy")};
        int ret = sol.solution(K, words);

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소의 반환 값은 " + ret + " 입니다.");
    }
}
