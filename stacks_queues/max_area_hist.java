import java.util.*;

public class Main {
    
    static List<Integer> nsr_i(List<Integer> arr) {
        int n = arr.size();
        Stack<Pair<Integer, Integer>> s = new Stack<>();
        List<Integer> result = new ArrayList<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.isEmpty() && s.peek().getKey() >= arr.get(i))
                s.pop();

            if (s.isEmpty())
                result.add(n);
            else
                result.add(s.peek().getValue());

            s.push(new Pair<>(arr.get(i), i));
        }

        Collections.reverse(result);
        return result;
    }

    static List<Integer> nsl_i(List<Integer> arr) {
        int n = arr.size();
        Stack<Pair<Integer, Integer>> s = new Stack<>();
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && s.peek().getKey() >= arr.get(i))
                s.pop();

            if (s.isEmpty())
                result.add(-1);
            else
                result.add(s.peek().getValue());

            s.push(new Pair<>(arr.get(i), i));
        }

        return result;
    }

    public static void main(String[] args) {
        List<Integer> hist = Arrays.asList(6, 2, 5, 4, 5, 1, 6);
        List<Integer> nsr_index = nsr_i(hist);
        List<Integer> nsl_index = nsl_i(hist);

        List<Integer> width = new ArrayList<>();
        for (int i = 0; i < hist.size(); i++) {
            int w = nsr_index.get(i) - nsl_index.get(i) - 1;
            width.add(w);
        }

        int max_area = 0;
        for (int i = 0; i < width.size(); i++) {
            int area = hist.get(i) * width.get(i);
            max_area = Math.max(max_area, area);
        }

        System.out.println(max_area);
    }
}
