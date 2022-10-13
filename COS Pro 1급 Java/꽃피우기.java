// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Solution {
    
    public boolean allBloomed(int[][] garden, int N, int M) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (garden[i][j] == 0) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    public void copy(int[][] a, int[][] b, int N, int M) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                a[i][j] = b[i][j];
            }
        }
    }
    
    int[] dy = { 1, -1, 0, 0 };
    int[] dx = { 0, 0, 1, -1 };
    
    public int solution(int[][] garden) {
        // 여기에 코드를 작성해주세요.
        int N = garden.length;
        int M = garden[0].length;
        
        if (allBloomed(garden, N, M)) {
            return 0;
        }
        
        int answer = 0;
        
        while (true) {
            int[][] copyGarden = new int[N][M];
            copy(copyGarden, garden, N, M);
            
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (garden[i][j] == 0) {
                        continue;
                    }
                    
                    for (int k = 0; k < 4; k++) {
                        int nextY = i + dy[k];
                        int nextX = j + dx[k];
                        
                        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) {
                            continue;
                        }
                        
                        copyGarden[nextY][nextX] = 1;
                    }
                }
            }
            
            answer++;
            
            if (allBloomed(copyGarden, N, M)) {
                return answer;
            }
            
            copy(garden, copyGarden, N, M);
        }
    }
    
    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] garden1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        int ret1 = sol.solution(garden1);
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret1 + " 입니다.");
        
        int[][] garden2 = {{1, 1}, {1, 1}};
        int ret2 = sol.solution(garden2);
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret2 + " 입니다.");
        
    }    
}
