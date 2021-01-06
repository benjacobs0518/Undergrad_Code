#include <iostream>
#include <vector>
#include "Library.h"


// Name(s):
//
// Complete numbered coding tasks.
// Answer the questions with "Answer: " in the comments by writing your answer in the comments.
// some experiments might result in non-running/non-compiling code. Leave these experiments in, but
// comment them out.
// Turn in run_library.cpp, Library.h, and Library.cpp on Canvas before the end of class.
// make sure to leave a comment here and on canvas with your name and the name(s) of your partners.

int main() {
    // 1) Instantiate a couple Books. Set their fields equal to some values.
    // Print out the values of the books' fields.
    Book a;
    a.title = "Harry Potter";
    a.author = "J.K. Rowling";
    std::cout << a.title << " by " << a.author << std::endl;

    Book b;
    b.author = "The Martian";
    b.author = "Andy Weir";
    std::cout << b.title << " by " << b.author << std::endl;

    std::cout << a << std::endl;

    // 2) Instantiate a Library
    Library * l = new Library();
    // 3) Add a void Donate(Book b) method to your Library class.
    // Your Library should store the new book at the end of its shelf.


    // 4) Donate one of the Books that you instantiated to your Library.
    l->Donate(a);

    // 5) Print out the books in the Library (use the given PrintBooks method)
    l->PrintBooks();

    // 6) Change the title and/or author of the book that you donated to
    // something different.
    a.title = "Not Harry Potter";
    // Print out the new book information, then print out the books in your
    std::cout << a.title << " by " << a.author << std::endl;
    l->PrintBooks();
    // Library. Did changing the Book information change it in your Library?
    //
    // Answer (and your hypothesis for why/why not):
    // No, it doesnt change because the book was donated before the change

    // 7) Create two Books that are separate structs (not pointers or references)
    // but that have the same information.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer:


    if(a==b){ //
      std::cout << "value comparison: equal" << std::endl;
    }
    else{
      std::cout << "value comparison: NOT equal" << std::endl;
    }


    // 8) Create two Book references to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer:

  Book &b1_ref = a;
  Book &b2_ref = b;
  if(b1_ref)


    // 9) Create two Book pointers to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer:


    // 10) Add a void Donate(Book b, int num_copies) method to your Library class.
    // your Library should add num_copies of Book b to its shelf.


    // 11) Finally, if you reach this far, work on finding a solution to making it so
    // that you would be able to do any of the comparisons from # 7, 8, and 9
}
