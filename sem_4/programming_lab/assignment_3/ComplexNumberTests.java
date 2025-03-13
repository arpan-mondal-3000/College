import java.io.File;
import java.util.Scanner;

public class ComplexNumberTests {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("tests.txt"));

        int n = sc.nextInt();
        ComplexNumber[] cnArr = new ComplexNumber[n];
        for (int i = 0; i < n; i++) {
            double real = sc.nextDouble();
            double img = sc.nextDouble();
            cnArr[i] = new ComplexNumber(real, img);
        }
        System.out.println("Printing the complex numbers in the array: ");
        ComplexNumber cn = new ComplexNumber();
        for (ComplexNumber c : cnArr) {
            System.out.println(c);
            cn.add(c);
        }
        System.out.println("Addition result: " + cn);
        sc.close();
    }
}
