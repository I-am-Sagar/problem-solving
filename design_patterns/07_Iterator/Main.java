import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

// Book class
class Book {
    private String title;
    private String author;
    private int year;

    public Book(String title, String author, int year) {
        this.title = title;
        this.author = author;
        this.year = year;
    }

    @Override
    public String toString() {
        return title + " by " + author + ", " + year;
    }
}

// Library class
class Library implements Iterable<Book> {
    private List<Book> books = new ArrayList<>();

    public void addBook(Book book) {
        books.add(book);
    }

    @Override
    public Iterator<Book> iterator() {
        return new LibraryIterator(books);
    }

    public Iterable<Book> getBooksByAuthor(String author) {
        return new LibraryAuthorIterable(books, author);
    }

    public Iterable<Book> getBooksByYear(int year) {
        return new LibraryYearIterable(books, year);
    }
}

// LibraryIterator class
class LibraryIterator implements Iterator<Book> {
    private List<Book> books;
    private int index;

    public LibraryIterator(List<Book> books) {
        this.books = books;
        this.index = 0;
    }

    @Override
    public boolean hasNext() {
        return index < books.size();
    }

    @Override
    public Book next() {
        return books.get(index++);
    }
}

// LibraryAuthorIterable class
class LibraryAuthorIterable implements Iterable<Book> {
    private List<Book> books;

    public LibraryAuthorIterable(List<Book> books, String author) {
        this.books = new ArrayList<>();
        for (Book book : books) {
            if (book.toString().contains(author)) {
                this.books.add(book);
            }
        }
    }

    @Override
    public Iterator<Book> iterator() {
        return books.iterator();
    }
}

// LibraryYearIterable class
class LibraryYearIterable implements Iterable<Book> {
    private List<Book> books;

    public LibraryYearIterable(List<Book> books, int year) {
        this.books = new ArrayList<>();
        for (Book book : books) {
            if (book.toString().contains(Integer.toString(year))) {
                this.books.add(book);
            }
        }
    }

    @Override
    public Iterator<Book> iterator() {
        return books.iterator();
    }
}

// Main class
public class Main {
    public static void main(String[] args) {
        Library library = new Library();
        library.addBook(new Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
        library.addBook(new Book("1984", "George Orwell", 1949));
        library.addBook(new Book("To Kill a Mockingbird", "Harper Lee", 1960));
        library.addBook(new Book("Animal Farm", "George Orwell", 1945));

        System.out.println("All books in the library:");
        for (Book book : library) {
            System.out.println(book);
        }

        System.out.println("\nBooks by George Orwell:");
        for (Book book : library.getBooksByAuthor("George Orwell")) {
            System.out.println(book);
        }

        System.out.println("\nBooks published in 1945:");
        for (Book book : library.getBooksByYear(1945)) {
            System.out.println(book);
        }
    }
}
