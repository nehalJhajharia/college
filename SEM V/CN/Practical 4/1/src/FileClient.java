import java.net.*;
import java.io.*;
import java.util.Scanner;

public class FileClient {
    Scanner sc = new Scanner(System.in);
    private Socket socket = null;
    private DataInputStream inputStream = null;
    private DataOutputStream outputStream = null;

    public FileClient(String address, int port) {
        try {
            socket = new Socket(address, port);
            System.out.println("Connected");

            inputStream = new DataInputStream(
                    new BufferedInputStream(socket.getInputStream()));
            outputStream = new DataOutputStream(socket.getOutputStream());

            try {
                String file_name = sc.nextLine();
                outputStream.writeUTF(file_name);
                String signal = inputStream.readUTF();
                System.out.println(signal);

                System.out.println("Receiving file...");
                FileTransferProcessor ftp = new FileTransferProcessor(socket);
                ftp.receiveFile(file_name);
            } catch (IOException e) {
                System.out.println(e);
            }

            System.out.println("Closing connection...");
            inputStream.close();
            outputStream.close();
            socket.close();
            System.out.println("Connection closed.");
        } catch (UnknownHostException u) {
            System.out.println(u);
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        Info info = new Info();
        FileClient client = new FileClient(info.ip_addr, info.port);
    }
}
