#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title, author;
    int isbn;
public:
    void setBookDetails(string t, string a, int i) {
        title = t;
        author = a;
        isbn = i;
    }
};

class Borrower {
protected:
    string name;
    int id;
public:
    void setBorrowerDetails(string n, int i) {
        name = n;
        id = i;
    }
};

class Library : public Book, public Borrower {
public:
    void borrowBook() {
        cout << "Borrower " << name << " (ID: " << id << ") has borrowed \"" << title << "\" by " << author << " (ISBN: " << isbn << ")." << endl;
    }

    void returnBook() {
        cout << "Borrower " << name << " (ID: " << id << ") has returned \"" << title << "\" by " << author << " (ISBN: " << isbn << ")." << endl;
    }
};

int main() {
    string title, author, name;
    int isbn, id, action;

    cout << "Enter book details:" << endl;
    cout << "Title: ";
    cin >> title;
    cout << "Author: ";
    cin >> author;
    cout << "ISBN: ";
    cin >> isbn;

    cout << "Enter borrower details:" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "ID: ";
    cin >> id;

    cout << "Enter action (1 for borrow, 2 for return): ";
    cin >> action;

    Library library;
    library.setBookDetails(title, author, isbn);
    library.setBorrowerDetails(name, id);

    if (action == 1) {
        library.borrowBook();
    } else if (action == 2) {
        library.returnBook();
    } else {
        cout << "Invalid action." << endl;
    }

    return 0;
}
