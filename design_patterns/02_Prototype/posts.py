import copy

class SocialMediaPost:
    def __init__(self, content, author, likes=0, comments=[]):
        self.content = content
        self.author = author
        self.likes = likes
        self.comments = comments

    def add_comment(self, comment):
        self.comments.append(comment)

    def display(self):
        print("Content:", self.content)
        print("Author:", self.author)
        print("Likes:", self.likes)
        print("Comments:", self.comments)

    def clone(self):
        # Use the built-in copy module to perform a deep copy of the object
        return copy.deepcopy(self)


# Example of using the Prototype pattern
if __name__ == "__main__":
    # Create a prototype post
    original_post = SocialMediaPost("Excited to launch our new product!", "John Doe")

    # Add some comments
    original_post.add_comment("Looks great!")
    original_post.add_comment("Can't wait to try it out!")

    # Display original post
    print("Original Post:")
    original_post.display()
    print()

    # Clone the original post and make slight modifications
    cloned_post = original_post.clone()
    cloned_post.content = "Check out our latest update!"
    cloned_post.add_comment("Interesting...")
    cloned_post.likes = 10

    # Display cloned post
    print("Cloned Post:")
    cloned_post.display()
