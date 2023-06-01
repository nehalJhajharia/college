from hashlib import sha256

plain_text = input("Enter plain text: ")

sha_digest = sha256(plain_text.encode()).hexdigest()

print("SHA: %s" % sha_digest)

from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

key = get_random_bytes(16)
cipher = AES.new(key, AES.MODE_EAX)
ciphertext, tag = cipher.encrypt_and_digest(plain_text.encode())
print("AES digest: %s" % ciphertext)


d_cipher = AES.new(key, AES.MODE_EAX, nonce=cipher.nonce)
decrypted = d_cipher.decrypt(ciphertext)
print("AES decrypted: %s" % decrypted.decode())