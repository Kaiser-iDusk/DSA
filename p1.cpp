#include<bits/stdc++.h>
using namespace std;
class Complex{
    float real, imag;
    public:
        Complex():real(0), imag(0){
            
        }
        Complex(float r, float i): real(r), imag(i){
            
        }
        void show(){
            cout << real << " + i" << imag << endl;
        }
        Complex operator+(Complex &c2){
            Complex c3;
            c3.real = this->real + c2.real;
            c3.imag = this->imag + c2.imag;
            return c3;
        }

};
int main(){
    Complex c1(2, 3), c2(3, 2);
    c1.show();
    c2.show();
    Complex c3 = c1 + c2;
    c3.show();
    return 0;
}