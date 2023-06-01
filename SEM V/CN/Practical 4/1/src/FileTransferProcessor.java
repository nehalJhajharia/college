import java.io.*;
import java.net.Socket;

public class FileTransferProcessor {
    Socket socket;
    InputStream is;
    FileOutputStream fos;
    BufferedOutputStream bos;
    int bufferSize;


    FileTransferProcessor(Socket client) {
        socket = client;
        is = null;
        fos = null;
        bos = null;
        bufferSize = 0;
    }

    void receiveFile(String fileName) {
        try {
            System.out.println("Receiving file...");
            is = socket.getInputStream();
            bufferSize = socket.getReceiveBufferSize();
            System.out.println("Buffer size: " + bufferSize);
            fos = new FileOutputStream(fileName);
            bos = new BufferedOutputStream(fos);
            byte[] bytes = new byte[bufferSize];
            int count;
            while ((count = is.read(bytes)) >= 0) {
                bos.write(bytes, 0, count);
            }
            bos.close();
            is.close();
            System.out.println("File RECEIVED");
        } catch (IOException e) {
            System.out.println("Error while receiving!!");
            e.printStackTrace();
        }
    }

    void sendFile(File file) {
        FileInputStream fis;
        BufferedInputStream bis;
        BufferedOutputStream out;
        byte[] buffer = new byte[8192];
        try {
            System.out.println("Sending file...");
            fis = new FileInputStream(file);
            bis = new BufferedInputStream(fis);
            out = new BufferedOutputStream(socket.getOutputStream());
            int count;
            while ((count = bis.read(buffer)) > 0) {
                out.write(buffer, 0, count);
            }
            out.close();
            fis.close();
            bis.close();
            System.out.println("File SENT");
        } catch (IOException e) {
            System.out.println("Error while sending!!");
            e.printStackTrace();
        }
    }
}