// Implement Vernam cipher.

import java.util.*;

public class Vernam {
	static Scanner input = new Scanner(System.in);
	static String key = new String();
	static String plaintext = new String();
	static String ciphertext = new String();

	public static String encrypt(String text, String key) {
		String cipherText = "";
		int cipher[] = new int[key.length()];

		for (int i = 0; i < key.length(); i++) {
			cipher[i] = text.charAt(i) - 'A' + key.charAt(i) - 'A';
		}

		for (int i = 0; i < key.length(); i++) {
			if (cipher[i] > 25) {
				cipher[i] = cipher[i] - 26;
			}
		}

		for (int i = 0; i < key.length(); i++) {
			int x = cipher[i] + 'A';
			cipherText += (char) x;
		}

		return cipherText;
	}

	public static String decrypt(String s) {
		String text = "";

		int plain[] = new int[key.length()];

		for (int i = 0; i < key.length(); i++) {
			plain[i] = s.charAt(i) - 'A' - (key.charAt(i) - 'A');
		}

		for (int i = 0; i < key.length(); i++) {
			if (plain[i] < 0) {
				plain[i] = plain[i] + 26;
			}
		}

		for (int i = 0; i < key.length(); i++) {
			int x = plain[i] + 'A';
			text += (char) x;
		}

		return text;
	}

	public static void main(String[] args) {
		System.out.print("Enter key : ");
		key = input.nextLine().toUpperCase();
		System.out.print("Enter text : ");
		plaintext = input.nextLine().toUpperCase();

		ciphertext = encrypt(plaintext, key);

		System.out.println("Cipher Text : " + ciphertext);
		System.out.println("Decrypted Text : " + decrypt(ciphertext));
	}
}
