import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Работа с файлами
 */
public class Files {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(
                new File("sum.in"));
        System.setOut(new PrintStream("sum.out"));

        try (PrintStream out = new PrintStream("sum2.out")) {
            out.println("Hi, all!");
        }

        BigInteger a = in.nextBigInteger();
        BigInteger b = in.nextBigInteger();
        // Считаем сумму 2-х длинных целых
        BigInteger sum = a.add(b);
        // Выводим на экран
        System.out.println(sum);
    }
}
