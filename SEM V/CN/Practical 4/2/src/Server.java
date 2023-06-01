import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.*;

public class Server {
    private Socket socket = null;
    private ServerSocket serverSocket = null;
    private DataInputStream inputStream = null;
    private DataOutputStream outputStream = null;

    public Server(int port) {
        try {
            serverSocket = new ServerSocket(port);
            System.out.println("Server started");
            System.out.println("Waiting for a client...");
            socket = serverSocket.accept();
            System.out.println("Client accepted");
            inputStream = new DataInputStream(
                    new BufferedInputStream(socket.getInputStream()));
            outputStream = new DataOutputStream(socket.getOutputStream());

            String msg = "";
            try {
                msg = inputStream.readUTF();
                outputStream.writeUTF("pong");
                System.out.println(msg);
            } catch (IOException i) {
                System.out.println(i);
            }

            System.out.println("Closing connection...");
            socket.close();
            inputStream.close();
            serverSocket.close();
            System.out.println("Connection closed.");
        } catch (IOException i) {
            System.out.println(i);
        }
    }

    public static void main(String[] args) {
        Info info = new Info();
        Server server = new Server(info.port);
    }
}
