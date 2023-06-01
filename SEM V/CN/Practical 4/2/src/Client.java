import java.net.*;
import java.io.*;
import java.util.Scanner;

public class Client {
    Scanner sc = new Scanner(System.in);
    private Socket socket = null;
    private DataInputStream inputStream = null;
    private DataOutputStream outputStream = null;

    public Client(String address, int port) {
        try {
            socket = new Socket(address, port);
            System.out.println("Connected");

            inputStream = new DataInputStream(
                    new BufferedInputStream(socket.getInputStream()));
            outputStream = new DataOutputStream(socket.getOutputStream());
        } catch (UnknownHostException u) {
            System.out.println(u);
        } catch (IOException i) {
            System.out.println(i);
        }

        String msg = "";
        try {
            double startTime = System.nanoTime();
            outputStream.writeUTF("ping");
            msg = inputStream.readUTF();
            double endTime = System.nanoTime();
            System.out.println(msg);

            double execTime = (endTime - startTime) / 1000000;
            System.out.println("RTT = " + execTime + " milliseconds.");

            System.out.println("Closing connection...");
            inputStream.close();
            outputStream.close();
            socket.close();
            System.out.println("Connection closed.");
        } catch (IOException i) {
            System.out.println(i);
        }
    }

    public static void main(String[] args) {
        Info info = new Info();
        Client client = new Client(info.ip_addr, info.port);
    }
}
