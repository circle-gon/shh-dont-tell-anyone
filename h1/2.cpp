#include <string>
#include <iostream>
#include <array>

using namespace std;

struct Book {
    string title, author;
    int year;
    Book() {}
    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }
};

ostream& operator<<(ostream& os, Book& book) {
    os << "Title: " << book.title << "\n";
    os << "Author: " << book.author << "\n";
    os << "Year: " << book.year << "\n\n";
    return os;
}

istream& operator>>(istream& is, Book& book) {
    getline(is, book.title);
    getline(is, book.author);
    is >> book.year;
    return is;
}

int main() {
    array<Book, 3> books = {
        Book("Philosopher's Stone", "JK Rowling", 1997),
        Book("1984", "George Orwell", 1949),
        Book("Animal Farm", "George Orwell", 1945)
    };

    for (auto& book: books) {
        cout << book;
    }

    return 0;
}