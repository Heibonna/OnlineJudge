#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class Rational {
public:
	Rational();
	Rational(int numerator, int denominator = 1);
	Rational(const Rational &r);                                    //constructor kopiujacy

	Rational operator+(Rational &r);
	Rational operator-(Rational &r);
    Rational operator*(Rational &r);
    Rational operator/(Rational &r);

	friend bool operator<(const Rational &r1, const Rational &r2);
    friend bool operator==(const Rational &r1, const Rational &r2);
	friend bool operator>(const Rational &r1, const Rational &r2);

	friend ostream& operator<<(ostream &output, Rational &r);
	friend istream& operator>>(istream &input, Rational &r);

private:
	int numerator;
	int denominator;

	static int gcd(int x, int y);
};

int Rational::gcd(int x, int y){
	while(y!=0) {
		int r = x%y;
		x = y;
		y = r;
	}

	return x;
}

inline Rational::Rational(){
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int x, int y){
    int gcd_value;
    if((gcd_value = gcd(x, y)) != 1){
        x = x / gcd_value;
        y = y / gcd_value;
    }
    this -> numerator = x;
    this -> denominator = y;
}

inline Rational::Rational(const Rational &r){
	this->numerator = r.numerator;
	this->denominator = r.denominator;
}

Rational Rational::operator+(Rational &r){
    int gcd_value;
    int num = (this -> numerator * r.denominator) + (this -> denominator * r.numerator);
    int den = r.denominator * this -> denominator;

    if((gcd_value = gcd(num, den)) != 1){
        num /= gcd_value;
        den /= gcd_value;
    }

    Rational sum(num,den);

    return sum;
}

Rational Rational::operator-(Rational &r){
    int num = (this -> numerator * r.denominator) - (this -> denominator * r.numerator);
    int den = r.denominator * this -> denominator;
    int gcd_value;
    if((gcd_value = gcd(num, den)) != 1){
        num /= gcd_value;
        den /= gcd_value;
    }

    Rational sum(num,den);

    return sum;
}

Rational Rational::operator*(Rational &r){
    int gcd_value;
    int num = (this -> numerator * r.numerator);
    int den = r.denominator * this -> denominator;

    if(den < 0){
        den = -den;
        num = -num;
    }
    if((gcd_value = gcd(num, den)) != 1){
        num /= gcd_value;
        den /= gcd_value;
    }

    Rational result(num,den);
    return result;
}

Rational Rational::operator/(Rational &r){
    int num = this -> numerator * r.denominator;
    int den = r.numerator * this -> denominator;
    int gcd_value;
    if(den < 0){
        den = -den;
        num = -num;
    }
    if((gcd_value = gcd(num, den)) != 1){
        num /= gcd_value;
        den /= gcd_value;
    }


    Rational result(num,den);
    return result;
}

ostream& operator<<(ostream &output, Rational &r){
	output << r.numerator;

	if(r.denominator!=1)
		output << "|" << r.denominator;

	return output;
}

istream& operator>>(istream &input, Rational &r){
	int nom, den, gcd_value; char l;
	input >> nom;
	input >> l;
    input >> den;

     if(den == 0){
        perror("Denominator cannot be 0 and must be separated by |");
    }
    else{
        if((gcd_value = Rational::gcd(nom, den)) != 1){
            nom = nom / gcd_value;
            den = den / gcd_value;
        }
        r.numerator = nom;
        r.denominator = den;
    }
    return input;
}

bool operator<(const Rational &r1, const Rational &r2){
    int den1 = r1.denominator, den2 = r2.denominator;
    int num1 = r1.numerator, num2 = r2.numerator;

    num1 *= den2;
    num2 *= den1;

    if(num1 < num2) return true;
    else return false;
}

bool operator==(const Rational &r1, const Rational &r2){
    int den1 = r1.denominator, den2 = r2.denominator;
    int num1 = r1.numerator, num2 = r2.numerator;

    num1 *= den2;
    num2 *= den1;

    if(num1 == num2) return true;
    else return false;
}

inline bool operator<=(const Rational &r1, const Rational &r2){

    if(r1 == r2 || r1 < r2) return true;
    else return false;
}

inline bool operator!=(const Rational &r1, const Rational &r2){

    if(!(r1 == r2)) return true;
    else return false;
}

inline bool operator>(const Rational &r1, const Rational &r2){
    if(!(r1 <= r2)) return true;
    else return false;
}

inline bool operator>=(const Rational &r1, const Rational &r2){
    if(!(r1 < r2)) return true;
    else return false;
}

int main(void) {
    string statement;
    int noobtest;
    char test;
    Rational* number1, number2, number3;

    int j = 0;

    while(cin >> statement){
        for(int i = 0; i < statement.size(); i++){

            else if(statement[i] <= 57 && statement[i] >= 48
               && statement[i+1] == '|' && statement[i+2]<= 57
               && statement[i+2] >= 48){
                if(number1 == 0) number1 = new Rational(statement[i] - '0', statement[i+2] - '0');
                else if(number2 == 0) number2 = new Rational(statement[i] - '0', statement[i+2] - '0');
                else number3 = new Rational(statement[i] - '0', statement[i+2] - '0');
                i += 2;
            }
            else if(statement[i] <= 57 && statement[i] >= 48
                    && statement[i+1]<= 57 && statement[i+1] >= 48){} //nwm liczba >9
            else if(statement[i] <= 57 && statement[i] >= 48){
                if(number1 == 0) number1 = new Rational(statement[i] - '0', 1);
                else if(number2 == 0) number2 = new Rational(statement[i] - '0', 1);
                else number3 = new Rational(statement[i] - '0', 1);
            }
            else if(statement[i] == '+' || statement[i] == '-'
                    || statement[i] == '*' statement[i] == '+' ){

            }
        }
    }
	return 0;
}

