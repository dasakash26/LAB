#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Book {
public:
  Book(const string &isbn, const string &title, const vector<string> &authors,
       double price)
      : isbn(isbn), title(title), authors(authors), price(price) {}

  const string &getISBN() const { return isbn; }
  const string &getTitle() const { return title; }
  const vector<string> &getAuthors() const { return authors; }
  double getPrice() const { return price; }

private:
  string isbn;
  string title;
  vector<string> authors;
  double price;
};

class BookStore {
public:
  void addBook(const Book &book, int copies) {
    for (int i = 0; i < copies; i++) {
      books.push_back(book);
    }
  }

  vector<string> getBooks() const {
    unordered_map<string, bool> uniqueISBNs;
    for (const auto &book : books) {
      uniqueISBNs[book.getISBN()] = true;
    }

    vector<string> result;
    for (const auto &pair : uniqueISBNs) {
      result.push_back(pair.first);
    }
    return result;
  }

  int getNumCopies(const string &isbn) const {
    int count = 0;
    for (const auto &book : books) {
      if (book.getISBN() == isbn) {
        count++;
      }
    }
    return count;
  }

  double getTotalPrice() const {
    double totalPrice = 0.0;
    for (const auto &book : books) {
      totalPrice += book.getPrice();
    }
    return totalPrice;
  }

private:
  vector<Book> books;
};

int main() {
  Book book1("978-1-56619-909-4", "Clean Code", {"Robert C. Martin"}, 49.99);
  Book book2("978-0-13-235088-4", "Effective Java", {"Joshua Bloch"}, 44.95);
  Book book3("978-0-19-960413-3", "The Pragmatic Programmer",
             {"Andrew Hunt", "David Thomas"}, 39.95);

  BookStore bookStore;
  bookStore.addBook(book1, 5);
  bookStore.addBook(book2, 3);
  bookStore.addBook(book3, 2);

  for (const auto &isbn : bookStore.getBooks()) {
    cout << "Title: " << bookStore.getNumCopies(isbn)
         << ", Copies: " << bookStore.getNumCopies(isbn) << endl;
  }

  cout << "Total Price: " << bookStore.getTotalPrice() << endl;

  return 0;
}
