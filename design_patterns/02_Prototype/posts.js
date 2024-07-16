class SocialMediaPost {
    constructor(content, author, likes=0, comments=[]) {
        this.content = content;
        this.author = author;
        this.likes = likes;
        this.comments = comments;
    }

    addComment(comment) {
        this.comments.push(comment);
    }

    display() {
        console.log("Content:", this.content);
        console.log("Author:", this.author);
        console.log("Likes:", this.likes);
        console.log("Comments:", this.comments);
    }

    clone() {
        // Perform a deep copy of the object
        return new SocialMediaPost(
            this.content,
            this.author,
            this.likes,
            this.comments.slice() // Create a shallow copy of comments array
        );
    }
}

// Example of using the Prototype pattern
// Create a prototype post
let originalPost = new SocialMediaPost("Excited to launch our new product!", "John Doe");

// Add some comments
originalPost.addComment("Looks great!");
originalPost.addComment("Can't wait to try it out!");

// Display original post
console.log("Original Post:");
originalPost.display();
console.log();

// Clone the original post and make slight modifications
let clonedPost = originalPost.clone();
clonedPost.content = "Check out our latest update!";
clonedPost.addComment("Interesting...");
clonedPost.likes = 10;

// Display cloned post
console.log("Cloned Post:");
clonedPost.display();
