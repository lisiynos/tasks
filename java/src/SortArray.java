import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

import static java.lang.System.out;
import static java.util.Arrays.sort;

/**
 * Сортировка массива из файла
 */
public class SortArray {
    public static void main(String[] args) throws FileNotFoundException {
        String ID = "sort";
        Scanner in = new Scanner(new File(ID + ".in"));
        System.setOut(new PrintStream(ID + ".out"));
        // Чтение входных данных
        int N = in.nextInt();
        int A[] = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = in.nextInt();
        }
        // Сортируем массив A
        sort(A);
        // Выводим массив в выходной файл
        for (int x : A) {
            out.print(x + " ");
        }
        out.println();
    }
}
