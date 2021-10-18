import java.util.*;

public class Palindrome {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String original, reverse = ""; // stores user entered value and it's reverse value

        System.out.println("Enter a string: ");
        original = sc.nextLine();

        int length = original.length();

        // reverse the original user input value
        for ( int i = length - 1; i >= 0; i-- ) {
            reverse = reverse + original.charAt(i);
        }

        // check equality of original value and reverse value
        if (original.equals(reverse)) {
            System.out.println(original + " is a palindrome string.");
        }
        else {
            System.out.println(original + " isn't a palindrome string.");
        }

    }

}
