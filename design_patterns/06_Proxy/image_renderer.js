class Image {
    display() {
        throw new Error("This method should be overridden.");
    }
}

class RealImage extends Image {
    constructor(filename) {
        super();
        this.filename = filename;
        this._loadImage();
    }

    _loadImage() {
        console.log(`Loading image '${this.filename}' from disk...`);
        // Simulate the delay of loading a large file
        setTimeout(() => {
            console.log(`Image '${this.filename}' loaded.`);
        }, 2000);
    }

    display() {
        console.log(`Displaying ${this.filename}`);
    }
}

class ProxyImage extends Image {
    constructor(filename) {
        super();
        this.filename = filename;
        this._realImage = null;
    }

    display() {
        if (this._realImage === null) {
            this._realImage = new RealImage(this.filename);
        }
        this._realImage.display();
    }
}

function main() {
    const images = [
        new ProxyImage("image1.jpg"),
        new ProxyImage("image2.jpg"),
        new ProxyImage("image3.jpg")
    ];

    console.log("User is opening the image viewer.");
    images[0].display();
    setTimeout(() => {
        console.log("User navigates to the next image.");
        images[1].display();
        setTimeout(() => {
            console.log("User goes back to the first image.");
            images[0].display();
        }, 2500);
    }, 2500);
}

main();
