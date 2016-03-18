import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Random;

/**
 * Генератор случайного массива
 * заданного размера
 */
public class GenArray {
    public static void main(String[] args)
            throws FileNotFoundException {
        System.setOut(new PrintStream("sort.in"));
        // Количество чисел
        int N = 100000;
        // Выводим это число в первую строку файла
        System.out.println(N);
        // Создаём генератор случайных чисел
        Random random = new Random();
        // В цикле генерируем сами числа
        for (int i = 0; i < N; i++) {
            System.out.print(random.nextInt(1000000000)
                    + " ");
        }
    }
}
