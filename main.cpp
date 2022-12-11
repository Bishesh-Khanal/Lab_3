#include <iostream>
#include <cmath>

using namespace std;

class Real{
    protected:
        int real;
    public:
        Real(){}

        Real(int real){
            setReal(real);
        }

        void setReal(int real){
            this->real = real;
        }
};

class Imaginary{
    protected:
        int imaginaryNumber;
        char character;
    public:
        Imaginary(){}

        Imaginary( int imaginaryNumber, char character){
            setNumber(imaginaryNumber);
            setCharacter(character);
        }

        void setNumber(int imaginaryNumber){
            this->imaginaryNumber = imaginaryNumber;
        }

        void setCharacter(char character){
            switch(character){
                case 'i': case 'j':
                    this->character = character;
                break;
                default:
                    throw "Invalid imaginary character has been entered!";
                break;
            }
        }
};

class Complex: public Imaginary, public Real{
    public:
        Complex(): Real(), Imaginary(){}
        Complex(int real, int imaginaryNumber, char character): Real(real), Imaginary(imaginaryNumber, character){}

        void operator-(){
            this->real *= -1;
            this->imaginaryNumber *= -1;
        }

        friend Complex operator*(Complex&, int);

        friend Complex operator+(Complex&, Complex&);

        friend Complex operator-(Complex&, Complex&);

        void operator+=(Complex& complex2){
            if( this->character == complex2.character ){
                this->setReal(this->real + complex2.real);
                this->setNumber(this->imaginaryNumber + complex2.imaginaryNumber);
                this->setCharacter(this->character);
            } else{
                throw "Dissimilar imaginary characters!";
            }
        }

        bool operator==(const Complex& complex)const{
            if(this->character == complex.character && this->real == complex.real && this->imaginaryNumber == complex.imaginaryNumber){
                return true;
            } else{
                return false;
            }
        }

        bool operator!=(const Complex& complex)const{
            if(this->character != complex.character || this->real != complex.real || this->imaginaryNumber != complex.imaginaryNumber){
                return true;
            } else{
                return false;
            }
        }

        bool operator>(const Complex& complex)const{
            return sqrt(pow(this->real, 2) + pow(this->imaginaryNumber, 2)) > sqrt(pow(complex.real, 2) + pow(complex.imaginaryNumber, 2));
        }

        friend ostream& operator<<(ostream&, Complex&);
};

ostream& operator<<(ostream& Operator, Complex& complex){
            if(complex.imaginaryNumber < 0){
                Operator << complex.real << complex.imaginaryNumber << complex.character << endl;
            } else{
                Operator << complex.real << "+" << complex.imaginaryNumber << complex.character << endl;
            }
            return Operator;
}

Complex operator*(Complex& complex, int scalar){
    Complex result;
    result.setReal(complex.real*scalar);
    result.setNumber(complex.imaginaryNumber*scalar);
    result.setCharacter(complex.character);
    return result;
}

Complex operator+(Complex& complex1, Complex& complex2){
        Complex result;
        if( complex1.character == complex2.character ){
            result.setReal(complex1.real + complex2.real);
            result.setNumber(complex1.imaginaryNumber + complex2.imaginaryNumber);
            result.setCharacter(complex1.character);
        } else{
            throw "Dissimilar imaginary characters!";
        }
        return result;
}

Complex operator-(Complex& complex1, Complex& complex2){
        Complex result;
        if( complex1.character == complex2.character ){
            result.setReal(complex1.real - complex2.real);
            result.setNumber(complex1.imaginaryNumber - complex2.imaginaryNumber);
            result.setCharacter(complex1.character);
        } else{
            throw "Dissimilar imaginary characters!";
        }
        return result;
}

int main(){
    try{
        Complex a(7,-14,'i');
        cout << a;
        -a;
        cout << a;
        Complex b = a*5;
        cout << b;
        Complex c = a+b;
        cout << c;
        Complex d = c-b;
        cout << d;
        d += c;
        cout << d;
        c = a;
        bool test = a==c;
        cout << test << endl;
        test = a==b;
        cout << test << endl;
        test = a!=c;
        cout << test << endl;
        test = a!=d;
        cout << test << endl;
        test = b>a;
        cout << test << endl;
        test = d>a;
        cout << test << endl;
    } catch(const char* error){
        cout << "Error: " << error << endl;
    } catch(...){
        cout << "An exception occured" << endl;
    }
}