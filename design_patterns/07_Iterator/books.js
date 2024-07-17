class Book {
  constructor(title, author, year) {
    this.title = title;
    this.author = author;
    this.year = year;
  }

  toString() {
    return `${this.title} by ${this.author}, ${this.year}`;
  }
}

class Library {
  constructor() {
    this.books = [];
  }

  addBook(book) {
    this.books.push(book);
  }

  [Symbol.iterator]() {
    return new LibraryIterator(this.books);
  }

  getBooksByAuthor(author) {
    return new LibraryAuthorIterator(this.books, author);
  }

  getBooksByYear(year) {
    return new LibraryYearIterator(this.books, year);
  }
}

class LibraryIterator {
  constructor(books) {
    this._books = books;
    this._index = 0;
  }

  next() {
    if (this._index < this._books.length) {
      return { value: this._books[this._index++], done: false };
    } else {
      return { done: true };
    }
  }
}

class LibraryAuthorIterator {
  constructor(books, author) {
    this._books = books.filter((book) => book.author === author);
    this._index = 0;
  }

  [Symbol.iterator]() {
    return this;
  }

  next() {
    if (this._index < this._books.length) {
      return { value: this._books[this._index++], done: false };
    } else {
      return { done: true };
    }
  }
}

class LibraryYearIterator {
  constructor(books, year) {
    this._books = books.filter((book) => book.year === year);
    this._index = 0;
  }

  [Symbol.iterator]() {
    return this;
  }

  next() {
    if (this._index < this._books.length) {
      return { value: this._books[this._index++], done: false };
    } else {
      return { done: true };
    }
  }
}

// Usage example
const library = new Library();

library.addBook(new Book('The Great Gatsby', 'F. Scott Fitzgerald', 1925));
library.addBook(new Book('1984', 'George Orwell', 1949));
library.addBook(new Book('To Kill a Mockingbird', 'Harper Lee', 1960));
library.addBook(new Book('Animal Farm', 'George Orwell', 1945));

console.log('All books in the library:');
// of => automatically calls next() for you, done flag as well! 
for (const book of library) {  // for loop is sequential 
  console.log(book.toString());
}

// How will you simulate pause? next() by yourself

console.log('\nBooks by George Orwell:');
for (const book of library.getBooksByAuthor('George Orwell')) {
  console.log(book.toString());
}

console.log('\nBooks published in 1945:');
for (const book of library.getBooksByYear(1945)) {
  console.log(book.toString());
}

// const iterator = library[Symbol.iterator]();

// console.log(iterator.next().value.toString())
// console.log(iterator.next().value.toString())
// console.log(iterator.next())
