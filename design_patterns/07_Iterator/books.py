class Book:
    def __init__(self, title, author, year):
        self.title = title
        self.author = author
        self.year = year

    def __str__(self):
        return f'{self.title} by {self.author}, {self.year}'

class Library:
    def __init__(self):
        self.books = []

    def add_book(self, book):
        self.books.append(book)

    def __iter__(self):
        return LibraryIterator(self.books)

    def get_books_by_author(self, author):
        return LibraryAuthorIterator(self.books, author)

    def get_books_by_year(self, year):
        return LibraryYearIterator(self.books, year)

class LibraryIterator:
    def __init__(self, books):
        self._books = books
        self._index = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self._index < len(self._books):
            result = self._books[self._index]
            self._index += 1
            return result
        else:
            raise StopIteration

class LibraryAuthorIterator:
    def __init__(self, books, author):
        self._books = [book for book in books if book.author == author]
        self._index = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self._index < len(self._books):
            result = self._books[self._index]
            self._index += 1
            return result
        else:
            raise StopIteration

class LibraryYearIterator:
    def __init__(self, books, year):
        self._books = [book for book in books if book.year == year]
        self._index = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self._index < len(self._books):
            result = self._books[self._index]
            self._index += 1
            return result
        else:
            raise StopIteration

if __name__ == "__main__":
    library = Library()
    library.add_book(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925))
    library.add_book(Book("1984", "George Orwell", 1949))
    library.add_book(Book("To Kill a Mockingbird", "Harper Lee", 1960))
    library.add_book(Book("Animal Farm", "George Orwell", 1945))

    print("All books in the library:")
    for book in library:
        print(book)

    print("\nBooks by George Orwell:")
    for book in library.get_books_by_author("George Orwell"):
        print(book)

    print("\nBooks published in 1945:")
    for book in library.get_books_by_year(1945):
        print(book)
