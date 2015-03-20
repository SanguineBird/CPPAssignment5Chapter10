/*
Meghan Moore
February 28, 2015
CIT 245 - Data Structures and Programming C++
Assignment 5 - Chapter 10
Purpose: Part 1:
  Create an int, a pointer to that int, and a pointer to that pointer.
Part 2:
  Demonstrate deep and shallow copy by making two classes.
*/

#include <iostream> //cin, cout, cerr
#include <cstdlib> //system
using namespace std;

class WrapArrayDeep{
  public:
    WrapArrayDeep();
    WrapArrayDeep(const WrapArrayDeep& wad);
    void display();
    void set(int index, char value){pch[index] = value;}
    int get(int index){return pch[index];}
    ~WrapArrayDeep();
  private:
    char *pch;
};

class WrapArrayShallow{
  public:
    WrapArrayShallow();
    WrapArrayShallow(const WrapArrayShallow& was);
    void display();
    void set(int index, char value){pch[index] = value;}
    int get(int index){return pch[index];}
    ~WrapArrayShallow();
  private:
    char *pch;
};

int main(){
  //part 1:
  cout << "This program section uses 3 variables:\ni = 7; pi, a pointer to i; and ppi, a pointer to pi.\n\n";
  
  int i = 7;
  int *pi = &i;
  cout << "pi = " << pi << endl;
  cout << "Address of pi: " << &pi << endl;
  cout << "Address of i: " << &i << endl;
  cout << "Dereference of pi: " << *pi << endl << endl;
  
  int **ppi;
  ppi = &pi;
  cout << "ppi = " << ppi << endl;
  cout << "Address of ppi: " << &ppi << endl;
  cout << "Dereference of ppi: " << *ppi << endl;
  cout << "Double dereference of ppi: " << **ppi << endl << endl;
  
  //part 2:
  WrapArrayDeep wad1;
  WrapArrayShallow was1;
  cout << "This section instantiates a wrapper class for a dynamic array of 5 elements.\n\n";
  
  cout << "WrapArrayDeep 1: \n";
  wad1.display();
  
  WrapArrayDeep wad2(wad1);
  cout << "WrapArrayDeep 2: Created using the copy constructor on 1:\n";
  wad2.display();
  
  wad1.set(0, '{');
  wad1.set(1, '|');
  wad1.set(2, '}');
  wad1.set(3, '~');
  wad1.set(4, '^');
  cout << "After changing the contents of WrapArrayDeep 1\nWrapArrayDeep 1:\n";
  wad1.display();
  cout << "WrapArrayDeep 2:\n";
  wad2.display();
  cout << endl;
  
  cout << "Now doing the same thing with WrapArrayShallow:\n\nWrapArrayShallow 1:\n";
  was1.display();
  
  WrapArrayShallow was2(was1);
  cout << "WrapArrayShallow 2: Created using the copy constructor on 1:\n";
  was2.display();
  
  was1.set(0, '{');
  was1.set(1, '|');
  was1.set(2, '}');
  was1.set(3, '~');
  was1.set(4, '^');
  cout << "After changing the contents of WrapArrayShallow 1\nWrapArrayShallow 1:\n";
  was1.display();
  cout << "WrapArrayShallow 2:\n";
  was2.display();
  cout << endl;
  
  system("pause");
  return 0;
} //end main

WrapArrayDeep::WrapArrayDeep(){
  pch = new char[5];
  *pch = 97;
  *(pch + 1) = 98;
  *(pch + 2) = 99;
  *(pch + 3) = 100;
  *(pch + 4) = 101;
} //end WAD default constructor
WrapArrayDeep::WrapArrayDeep(const WrapArrayDeep& wad){
  pch = new char[5];
  for(int i = 0; i < 5; i++)
    pch[i] = wad.pch[i];
} //end WAD copy constructor
void WrapArrayDeep::display(){
  for(int i = 0; i < 5; i++)
    cout << pch[i] << " ";
  cout << endl;
} //end WAD display
WrapArrayDeep::~WrapArrayDeep(){
  cout << "Calling destructor for WrapArrayDeep.\n";
  delete [] pch;
} //end WAD deconstructor

WrapArrayShallow::WrapArrayShallow(){
  pch = new char[5];
  pch[0] = 'a';
  pch[1] = 'b';
  pch[2] = 'c';
  pch[3] = 'd';
  pch[4] = 'e';
} //end WAS default constructor
WrapArrayShallow::WrapArrayShallow(const WrapArrayShallow& was){
  pch = new char[5];
  pch = was.pch;
} //end WAS copy constructor
void WrapArrayShallow::display(){
  for(int i = 0; i < 5; i++)
    cout << *(pch + i) << " ";
  cout << endl;
} //end WAS display
WrapArrayShallow::~WrapArrayShallow(){
  cout << "Calling destructor for WrapArrayShallow.\n";
  delete [] pch;
} //end WAS deconstructor
