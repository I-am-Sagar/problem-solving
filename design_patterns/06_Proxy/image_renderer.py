from abc import ABC, abstractmethod
import time

class Image(ABC):
    @abstractmethod
    def display(self):
        pass

class RealImage(Image):
    def __init__(self, filename):
        self.filename = filename
        self._load_image()

    def _load_image(self):
        # Simulate loading image from disk
        print(f"Loading image '{self.filename}' from disk...")
        time.sleep(2)  # Simulate the delay of loading a large file
        print(f"Image '{self.filename}' loaded.")

    def display(self):
        print(f"Displaying {self.filename}")

class ProxyImage(Image):
    def __init__(self, filename):
        self.filename = filename
        self._real_image = None

    def display(self):
        if self._real_image is None:
            self._real_image = RealImage(self.filename)
        self._real_image.display()

def main():
    images = [
        ProxyImage("image1.jpg"),
        ProxyImage("image2.jpg"),
        ProxyImage("image3.jpg")
    ]

    # Simulate user interacting with the image viewer
    print("User is opening the image viewer.")
    images[0].display()  # Only now the real image is loaded and displayed
    print("User navigates to the next image.")
    images[1].display()  # The second image is now loaded and displayed
    print("User goes back to the first image.")
    images[0].display()  # The first image is already loaded, so just display it

if __name__ == "__main__":
    main()
