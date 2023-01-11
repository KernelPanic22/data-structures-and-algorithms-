#include <iostream>
#include <cstdlib>

using namespace std;

class Book
{
public:
    Book(string title, string author, int pages);
    void print();
    ~Book();
    Book(const Book &b);
    Book &operator=(const Book &b);

    // we define a nested class inside the Book class
    class Bookmark
    {
    public:
        Bookmark(int page);
        void print();
        void setPage(int page);
        int getPage();
        Bookmark &operator=(const Bookmark &b);
        ~Bookmark();

    private:
        int page;
    };

private:
    string title;
    string author;
    int pages;
};

Book::Book(string title, string author, int pages)
{
    this->title = title;
    this->author = author;
    this->pages = pages;
}

void Book::print()
{
    cout << "Title: " << this->title << endl;
    cout << "Author: " << this->author << endl;
    cout << "Pages: " << this->pages << endl;
}

Book::~Book()
{
}

Book::Book(const Book &b)
{
    this->title = b.title;
    this->author = b.author;
    this->pages = b.pages;
}

Book &Book::operator=(const Book &b)
{
    if (this != &b)
    {
        this->title = b.title;
        this->author = b.author;
        this->pages = b.pages;
    }
    return *this;
}

Book::Bookmark::Bookmark(int page)
{
    this->page = page;
}

void Book::Bookmark::print()
{
    cout << "Page: " << this->page << endl;
}

void Book::Bookmark::setPage(int page)
{
    this->page = page;
}

int Book::Bookmark::getPage()
{
    return this->page;
}

Book::Bookmark &Book::Bookmark::operator=(const Bookmark &b)
{
    if (this != &b)
    {
        this->page = b.page;
    }
    return *this;
}

Book::Bookmark::~Bookmark()
{
}


int main()
{
    Book book("The C++ Programming Language", "Bjarne Stroustrup", 1000);
    Book::Bookmark bookmark(100);
    bookmark.print();
    book.print();
    bookmark.setPage(200);
    bookmark.print();
    return EXIT_SUCCESS;
}