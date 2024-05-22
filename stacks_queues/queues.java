import java.util.LinkedList;
import java.util.Queue;

public class queues {
    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>();
        Queue<String> q2 = new LinkedList<>();

        q1.add(1);
        q1.add(3);
        q1.add(7);

        for (int i = 4; i < 7; i++)
            q1.add(i); // Pushing 4, 5, 6

        // Total 6 elements in q1: Order of push: 1 3 7 4 5 6

        while (!q1.isEmpty()) {
            int temp = q1.peek();
            System.out.print(temp + " ");
            q1.poll();
        }
        System.out.println();

        q2.add("sagar");
        q2.add("vishnu");
        q2.add("shreya");

        while (!q2.isEmpty()) {
            String temp = q2.peek();
            System.out.print(temp + " ");
            q2.poll();
        }
        System.out.println();
    }
}
