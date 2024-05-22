import java.util.Stack;

public class stacks {
    public static void main(String[] args) {
        Stack<Integer> s1 = new Stack<>();
        Stack<String> s2 = new Stack<>();

        s1.push(1);
        s1.push(3);
        s1.push(7);

        for (int i = 4; i < 7; i++)
            s1.push(i); // Pushing 4, 5, 6

        // Total 6 elements in s1: Order of push: 1 3 7 4 5 6

        while (!s1.isEmpty()) {
            int temp = s1.pop();
            System.out.print(temp + " ");
        }
        System.out.println();

        s2.push("sagar");
        s2.push("vishnu");
        s2.push("shreya");

        while (!s2.isEmpty()) {
            String temp = s2.pop();
            System.out.print(temp + " ");
        }
        System.out.println();
    }
}
