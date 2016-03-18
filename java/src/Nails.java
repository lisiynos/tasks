import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

import static java.lang.Math.min;
import static java.lang.System.out;
import static java.util.Arrays.sort;

/**
 * Задача "Гвоздики"
 */
public class Nails {
    public static void main(String[] args) throws FileNotFoundException {
        String ID = "nails";
        Scanner in = new Scanner(new File(ID + ".in"));
        System.setOut(new PrintStream(ID + ".out"));
        // Чтение входных данных
        int N = in.nextInt();
        // Координаты гвоздиков
        int x[] = new int[N];
        for (int i = 0; i < N; i++) x[i] = in.nextInt();
        sort(x);
        // Константа-бесконечность
        final int INF = 100500;
        //    Гвоздики и ниточка
        //  x      x  x  x x    x  x x
        //  x------x  x  x x    x  x x
        //1 x------x--x  x x    x  x x
        //1 x------x  x--x x    x  x x
        //  0      #  6
        //- #      6  8
        int notConnect[] = new int[N];
        int connect[] = new int[N];
        notConnect[0] = 0;
        notConnect[1] = INF;
        connect[0] = INF;
        // Расстояние между первыми 2-мя гвоздиками
        connect[1] = x[1] - x[0];
        for (int i = 2; i < N; i++) {
            // Не соединяем i и i-1,
            // т.е. до этого гвоздики должны были быть соединены
            notConnect[i] = connect[i - 1];
            // Текущая ниточка
            int len = x[i] - x[i - 1];
            connect[i] = min(connect[i - 1] + len,
                    notConnect[i - 1] + len);
        }
        out.println(connect[N - 1]);
    }
}
