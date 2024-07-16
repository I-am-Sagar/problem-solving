import java.util.concurrent.TimeUnit;

interface Image {
    void display();
}

class RealImage implements Image {
    private String filename;

    public RealImage(String filename) {
        this.filename = filename;
        loadImage();
    }

    private void loadImage() {
        System.out.println("Loading image '" + filename + "' from disk...");
        try {
            // Simulate the delay of loading a large file
            TimeUnit.SECONDS.sleep(2);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Image '" + filename + "' loaded.");
    }

    @Override
    public void display() {
        System.out.println("Displaying " + filename);
    }
}

class ProxyImage implements Image {
    private String filename;
    private RealImage realImage;

    public ProxyImage(String filename) {
        this.filename = filename;
    }

    @Override
    public void display() {
        if (realImage == null) {
            realImage = new RealImage(filename);
        }
        realImage.display();
    }
}

public class Main {
    public static void main(String[] args) {
        Image[] images = {
            new ProxyImage("image1.jpg"),
            new ProxyImage("image2.jpg"),
            new ProxyImage("image3.jpg")
        };

        System.out.println("User is opening the image viewer.");
        images[0].display();
        System.out.println("User navigates to the next image.");
        images[1].display();
        System.out.println("User goes back to the first image.");
        images[0].display();
    }
}
