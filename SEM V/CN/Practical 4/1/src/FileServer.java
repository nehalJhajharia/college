import java.io.*;
import java.net.*;

public class FileServer {
    private Socket socket = null;
    private ServerSocket serverSocket = null;
    private DataInputStream inputStream = null;
    private DataOutputStream outputStream = null;
    private String pathname = "/Users/jhajharia/Desktop/";

    public FileServer(int port) {
        try {
            serverSocket = new ServerSocket(port);
            System.out.println("Server started");
            System.out.println("Waiting for a client...");

            socket = serverSocket.accept();
            System.out.println("Client accepted");
            inputStream = new DataInputStream(
                    new BufferedInputStream(socket.getInputStream()));
            outputStream = new DataOutputStream(socket.getOutputStream());

            try {
                String file_name = inputStream.readUTF();
                System.out.println("Searching for " + file_name + " ...");
                File file = new File(pathname + file_name);

                if(file != null) { // SEND FILE
                    System.out.println("Found");
                    outputStream.writeUTF("OK");
                    FileTransferProcessor ftp = new FileTransferProcessor(socket);
                    ftp.sendFile(file);
                } else {
                    System.out.println("Not Found!!");
                    outputStream.writeUTF("404 Not Found!!");
                }
            } catch (IOException e) {
                System.out.println(e);
            }

            System.out.println("Closing connection...");
            inputStream.close();
            outputStream.close();
            socket.close();
            serverSocket.close();
            System.out.println("Connection closed.");
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        Info info = new Info();
        FileServer server = new FileServer(info.port);
    }
}
