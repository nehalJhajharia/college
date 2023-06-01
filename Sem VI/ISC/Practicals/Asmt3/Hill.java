import java.util.*;

public class Hill {
    static Scanner input = new Scanner(System.in);

    static boolean falseKey(String text, String key) {
        if ((text.length() * text.length()) != key.length()) {
            System.out.println("Length of key should be square of the length of text.");
            return true;
        }

        return false;
    }

    static String encrypt(String text, String key) {
        int textVector[] = Matrix.generateVector(text);
        int cipherMatrix[][] = Matrix.generateMatrix(key);

        int cipherVector[] = Matrix.multiplyMatrixArray(cipherMatrix, textVector);
        System.out.println("Enrypted cipher vector : ");
        Matrix.printArray(cipherVector);

        String cipher = Matrix.generateString(cipherVector);
        System.out.print("Cipher text : " + cipher + "\n");

        return cipher;
    }

    static String decrypt(String cipher, String key) {
        int cipherVector[] = Matrix.generateVector(cipher);
        int cipherMatrix[][] = Matrix.generateMatrix(key);
        int inverseMatrix[][] = Matrix.invertMatrix(cipherMatrix);

        int textVector[] = Matrix.multiplyMatrixArray(inverseMatrix, cipherVector);
        System.out.println("Decrypted text vector : ");
        Matrix.printArray(textVector);

        String text = Matrix.generateString(textVector);

        return text;
    }

    public static void main(String[] args) {
        String text = "try";
        String key = "gybnqkurp";

        if (falseKey(text, key)) {
            return;
        }

        System.out.println("Plaintext : " + text);
        System.out.println("Key : " + key);
        System.out.println("\n\nEncrypting...");
        String cipher = encrypt(text, key);
        System.out.println("\n\nDecrypting...");
        String decipher = decrypt(cipher, key);
        System.out.println("Plaintext : " + decipher + "\n");
    }
}