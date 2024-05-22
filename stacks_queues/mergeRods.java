import java.util.PriorityQueue;

public class mergeRods {
    public static int minCostRodsMerge(int[] arr) {
        int cost = 0;

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int x : arr)
            minHeap.add(x);

        while (minHeap.size() > 1) {
            int rod1 = minHeap.poll();
            int rod2 = minHeap.poll();

            cost += rod1 + rod2;

            minHeap.add(rod1 + rod2);
        }

        return cost;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 2, 1, 4};

        System.out.println(minCostRodsMerge(arr));
    }
}
