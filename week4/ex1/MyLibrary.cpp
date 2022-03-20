#define _CRT_SECURE_NO_WARNINGS
#include "MyLibrary.h"
#include <cstdio>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <fstream>
#include <cstdarg>

void MyLibrary::print_books()
{
    output_stream << "Found " << books_number << " books" << endl;
    for (int i = 0; i < books_number; i++)
        output_stream << "Book: " << i << " " << books[i] << endl;
}

MyLibrary::~MyLibrary()
{
    delete[] books;
}

void MyLibrary::update_books_id_by_index(int book_index, int book_id)
{
    if (book_index < books_number)
        this->books[book_index] = book_id;
}

MyLibrary::MyLibrary(ostream& output_stream) : output_stream(output_stream)
{
    this->books_number  = -1;
    this->books         = nullptr;
}

MyLibrary::MyLibrary(ostream& output_stream, int books_number, int* books) : output_stream(output_stream)
{
    this->books_number  = books_number;
    this->books          = new int[books_number];
    for (int i = 0; i < books_number; i++)
        this->books[i] = books[i];
}

MyLibrary::MyLibrary(ostream& output_stream, int books_number, int min, int max) : output_stream(output_stream)
{
    this->books_number = books_number;
    this->books        = new int[books_number];
    for (int i = 0; i < books_number; i++)
        this->books[i] = rand() % (max - min) + min;
}

MyLibrary::MyLibrary(ostream& output_stream, const char* books_values) : output_stream(output_stream)
{
    char* books = new char[strlen(books_values) + 1];
    strcpy(books, books_values);
    int count = 0;
    for (int i = 0; books[i]; i++)
        if (books[i] == ';')
            count++;
 
    this->books_number = count + 1;
    this->books = new int[this->books_number];
    char* token = strtok(books, ";");
    count = 0;
    while (token)
    {
        int id = 0;
        for (int i = 0; token[i]; i++) // token ="357 \0"
            id = id * 10 + token[i] - '0';
        this->books[count++] = id;
        token = strtok(NULL, ";");
    }
}

MyLibrary::MyLibrary(ostream& output_stream, int books_count, ...) : output_stream(output_stream)
{
    this->books_number = books_count;
    this->books        = new int[books_count];
    va_list args;
    va_start(args, books_count);
    for (int i = 0; i < books_count; i++)
        this->books[i] = va_arg(args, int);
    va_end(args);
}

MyLibrary::MyLibrary(const MyLibrary& other) : MyLibrary(other.output_stream, other.books_number, other.books) { }
 
//MyLibrary::MyLibrary(const MyLibrary& other) : output_stream(other.output_stream)
//{
//
//    this->books_number = other.books_number;
//    this->books        = new int[this->books_number];
//    for (int i = 0; i < this->books_number; i++)
//        this->books[i] = other.books[i];
//}