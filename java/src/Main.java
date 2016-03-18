import java.math.BigInteger;
import java.util.Arrays;

import static java.lang.System.out;

public class Main {

    public static void main(String[] args) {
        // Целые числа
        byte b = 1; // -128..128
        short s = 32767;
        int ii = 1; // 4-байтное целое - рекомендуется
        long l = 100000000000000L; // 8-байтное целое
        // Вещественные числа
        float f = 1.1f;
        double d = 1.0; // <-- Рекомендуется
        // Символьный тип
        char c = 'A';
        // Логический тип
        boolean logic = true; // false

        // Одномерный массив int
        int array[] = new int[100];
        out.println("array.length = " + array.length);

        // Инициализация массива
        int array2[] = {3, 10, 121, 213, -3};
        // Сортировка
        Arrays.sort(array2);
        // Вывод массива с помощью индексов
        for (int i = 0; i < array2.length; i++) {
            out.println("array2[" + i + "] = "
                    + array2[i]);
        }
        // Вывод с помощью foreach
        for (int i : array2) {
            out.printf("%d ", i);
        }
        out.println();
        double p = 2 * Math.PI;
        out.printf("%.3f%n", p);

        int array2D[][] = new int[3][4];
        // Ввыводим все элементы массива
        for (int[] line : array2D) {
            for (int x : line) {
                System.out.print(x + " ");
            }
            System.out.println();
        }

        BigInteger a = new BigInteger("123456789012346567890", 10);
        System.out.println(a.toString());
        a = a.add(new BigInteger("1000"));
        a = a.multiply(new BigInteger("100000"));
        System.out.println(a);
    }
}
