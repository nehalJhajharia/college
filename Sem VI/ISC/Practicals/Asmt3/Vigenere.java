// Encryption and decryption using Vigenere cipher.

class Vigenere {
    static String generateKey(String str, String key) {
        int l = str.length();
        for (int i = 0;; i++) {
            if (l == i) {
                i = 0;
            }
            if (key.length() == str.length()) {
                break;
            }

            key += (key.charAt(i));
        }

        return key;
    }

    static String encrypt(String str, String key) {
        String ciphertext = "";
        for (int i = 0; i < str.length(); i++) {
            int x = (str.charAt(i) + key.charAt(i)) % 26;
            x += 'A';
            ciphertext += (char) (x);
        }

        return ciphertext;
    }

    static String decrypt(String ciphertext, String key) {
        String orig_text = "";

        for (int i = 0; i < ciphertext.length() &&
                i < key.length(); i++) {
            int x = (ciphertext.charAt(i) -
                    key.charAt(i) + 26) % 26;

            x += 'A';
            orig_text += (char) (x);
        }
        return orig_text;
    }

    public static void main(String[] args) {
        String str = "PRACTICALTHREE";
        String keyword = "NEHAL";

        String key = generateKey(str, keyword);
        String ciphertext = encrypt(str, key);

        System.out.println("Ciphertext : " + ciphertext + "\n");
        System.out.println("Decrypted Text : " + decrypt(ciphertext, key));
    }
}
