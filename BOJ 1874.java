import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

/**
 * @author jaime
 * @title BOJ1874
 * @see\n <pre>
 * </pre>
 * @since 2022-06-04
 */
public class BOJ1874 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Queue<Integer> q = new LinkedList<>();
        Stack<Integer> stk = new Stack<>();

        /**
         * 큐에 입력받은 순서대로 넣어주고
         */
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();

            q.add(num);
        }

        /**
         * 큐의 제일 첫 번째 숫자에 대해
         * 연산을 진행
         */
        int idx = 1;
        String answer = "";

        for (int i = 0; i < q.peek(); i++) {
            stk.push(idx++);
            answer += "+";
        }

        answer += "-";
        q.remove();
        stk.pop();

        /**
         * 두 번째 숫자부터 끝까지 순차적으로 연산 진행
         * 1. 스택이 비어있거나 스택의 top이 현재 출력하고자 하는 숫자보다 작을 경우 해당 숫자가 스택의 top이 될 때까지 추가
         * 2. 스택의 top이 현재 출력하고자 하는 숫자와 같을 경우 pop
         * 3. 스택의 top이 현재 출력하고자 하는 숫자보다 클 경우 불가능한 경우이므로 impossible 변수에 true 후 break
         */
        boolean impossible = false;

        while(true) {
            if (q.isEmpty()) {
                break;
            }

            int cur = q.peek();

            if (stk.empty() || cur > stk.peek()) {
                stk.push(idx++);
                answer += "+";
            }
            else if (cur == stk.peek()) {
                answer += "-";

                q.remove();
                stk.pop();
            }
            else if (cur < stk.peek()) {
                impossible = true;

                break;
            }
        }

        /**
         * 불가능하면 NO
         * 가능하면 answer의 각 기호를 줄 바꿈하며 출력
         */
        if (impossible) {
            System.out.println("NO");
        } else {
            for (int i = 0; i < answer.length(); i++) {
                System.out.println(answer.charAt(i));
            }
        }
    }
}
