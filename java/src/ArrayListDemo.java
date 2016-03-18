import java.util.*;

/**
 * Массив, увеличивающийся по мере добавления элементов
 * Аналог: std::vector
 */
public class ArrayListDemo {
    public static void main(String[] args) {
        Vector<Integer> v1 = new Vector<>(2, 0);
        // Добавить элемент в конец
        v1.add(100);
        v1.add(1002);
        //v1.remove(10);
        for (int x : v1) {
            System.out.println(x);
        }

        // Множества
        Set<Integer> s1 = new HashSet<>();
        s1.add(2);
        s1.add(2);
        s1.add(3);
        for (int i : s1) {
            System.out.println("Element: " + i);
        }
        if (s1.contains(2)) {
            System.out.println("2 found!");
        }
        s1.remove(2);

        // Map
        Map<String, String> map = new HashMap<>();
        map = new TreeMap<>();
        // Добавляем что-то в Map
        map.put("Hi", "Привет");
        map.put("Bye", "Пока");
        // Получаем значения с помощью get
        System.out.println(map.get("Hi"));

        // Stack
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        System.out.println("Stack: " + stack.pop());
        System.out.println("Stack: " + stack.pop());

        // Queue
        Queue<String> queue = new LinkedList<>();
        Deque<String> deque = new ArrayDeque<>();
    }
}
