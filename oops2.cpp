#include <iostream>
# include <string>
using namespace std;

// Overriding
class Parent {
public : 
    void show(){
        cout<<"Parent class show..\n";
    }   
    virtual void hello(){
        cout<<"Parent hello \n"; // virtual function
    }
   };
class Child : public Parent {
public : 
    void show(){
        cout<<"child class show..\n";
    }   
    virtual void hello(){
        cout<<"Parent hello \n"; // redefined
    }
   };
int main(){ 
    Child c1;
    Parent *ptr;

    ptr = & c1;
    ptr -> hello();
    return 0;
}   