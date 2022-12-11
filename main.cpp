#include <iostream>

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
        int number;
        char character;
    public:
        Imaginary(){}

        Imaginary( int number, char character){
            setNumber(number);
            setCharacter(character);
        }

        void setNumber(int number){
            this->number = number;
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
        Complex(int real, int number, char character): Real(real), Imaginary(number, character){}

        void operator-(){
            this->real *= -1;
            this->number *= -1;
        }

        friend Complex operator*(Complex&, int);

        friend Complex operator+(Complex&, Complex&);

        friend Complex operator-(Complex&, Complex&);

        void operator+=(Complex& complex2){
            if( this->character == complex2.character ){
                this->setReal(this->real + complex2.real);
                this->setNumber(this->number + complex2.number);
                this->setCharacter(this->character);
            } else{
                throw "Dissimilar imaginary characters!";
            }
        }

        bool operator==(const Complex& complex)const{
            if(this->character == complex.character && this->real == complex.real && this->number == complex.number){
                return true;
            } else{
                return false;
            }
        }

        bool operator!=(const Complex& complex)const{
            if(this->character != complex.character || this->real != complex.real || this->number != complex.number){
                return true;
            } else{
                return false;
            }
        }

        bool operator>(const Complex& complex)const{
            if(this->number > complex.number ){
                return true;
            } else{
                return false;
            }
        }

        friend ostream& operator<<(ostream&, Complex&);
};

ostream& operator<<(ostream& Operator, Complex& complex){
            if(complex.number < 0){
                Operator << complex.real << complex.number << complex.character << endl;
            } else{
                Operator << complex.real << "+" << complex.number << complex.character << endl;
            }
            return Operator;
}

Complex operator*(Complex& complex, int scalar){
    Complex result;
    result.setReal(complex.real*scalar);
    result.setNumber(complex.number*scalar);
    result.setCharacter(complex.character);
    return result;
}

Complex operator+(Complex& complex1, Complex& complex2){
        Complex result;
        if( complex1.character == complex2.character ){
            result.setReal(complex1.real + complex2.real);
            result.setNumber(complex1.number + complex2.number);
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
            result.setNumber(complex1.number - complex2.number);
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
        test = a>d;
        cout << test << endl;
    } catch(const char* error){
        cout << "Error: " << error << endl;
    } catch(...){
        cout << "An exception occured" << endl;
    }
}