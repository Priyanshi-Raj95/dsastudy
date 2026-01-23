#include <iostream>

using namespace std;

class User {
private :
   int id;
   string password;

public :
   string username;

   User(int id){
      this-> id = id;
    }
    // Getter
    string getPassword(){
        return password;
    }
    //Setter
    void setPassword(string password){
        this -> password = password;
    }
   };
// operator overloading
class complex{
    int real;
    int img;
public:
    complex(int r, int i){
        real = r;
        img = i;
    }
    void showNum(){
        cout<<real << " + "<<img<<"i \n";
    }
    void operator + (complex &c2){
        int resReal = this ->real + c2.real;
        int resImg = this ->img + c2.img;
        complex c3 (resReal, resImg);
        cout<< "res = ";
        c3.showNum();
    }
};
int main(){ 
    User u1(110);
    u1.username = "Priyanshi";
    u1.setPassword("75jjguyt87t8");

    cout<<"Username : "<<u1.username<<endl;
    cout<<"pass : "<<u1.getPassword()<<endl;
    //
    complex c1(1,2);
    complex c2(3,4);
    c1+c2;
    return 0;
}   