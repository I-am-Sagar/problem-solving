import java.util.ArrayList;
import java.util.List;

public class SocialMediaPost implements Cloneable {
    private String content;
    private String author;
    private int likes;
    private List<String> comments;

    public SocialMediaPost(String content, String author, int likes, List<String> comments) {
        this.content = content;
        this.author = author;
        this.likes = likes;
        this.comments = comments;
    }

    public SocialMediaPost(String content, String author) {
        this(content, author, 0, new ArrayList<>());
    }

    public void addComment(String comment) {
        this.comments.add(comment);
    }

    public void display() {
        System.out.println("Content: " + this.content);
        System.out.println("Author: " + this.author);
        System.out.println("Likes: " + this.likes);
        System.out.println("Comments: " + this.comments);
    }

    // For deep copy purposes
    @Override
    public SocialMediaPost clone() {
        try {
            // Perform a deep copy of the object
            SocialMediaPost clonedPost = (SocialMediaPost) super.clone();
            clonedPost.comments = new ArrayList<>(this.comments);
            return clonedPost;
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static void main(String[] args) {
        // Create a prototype post
        SocialMediaPost originalPost = new SocialMediaPost("Excited to launch our new product!", "John Doe");

        // Add some comments
        originalPost.addComment("Looks great!");
        originalPost.addComment("Can't wait to try it out!");

        // Display original post
        System.out.println("Original Post:");
        originalPost.display();
        System.out.println();

        // Clone the original post and make slight modifications
        SocialMediaPost clonedPost = originalPost.clone();
        clonedPost.content = "Check out our latest update!";
        clonedPost.addComment("Interesting...");
        clonedPost.likes = 10;

        // Display cloned post
        System.out.println("Cloned Post:");
        clonedPost.display();
    }
}
