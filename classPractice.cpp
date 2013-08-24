#include <iostream>
#include "classPractice.h"
#include <cmath>

 
using namespace std;

Fraction::Fraction(){
	num =0;
	denom =1;
}

Fraction::Fraction(int n, int d) {
	num = n;
	denom =d;
}

void Fraction::print(){
	cout << num << '/' << denom;
}

void Fraction::setNum(int n){
	num = n;
}
void Fraction::setDenom(int d){
	denom = d;
}
int Fraction::getNum(){
	return num;
}
int Fraction::getDenom(){
	return denom;
}

int Fraction::gcd(){
	int gcd;
	Fraction F;
	F.setDenom(denom);
	F.setNum(num);
	while (F.denom != 0){
		gcd = F.num % F.denom;
		F.num = F.denom;
		F.denom = gcd;

	}
	return F.num;	
}

Fraction Fraction::reduce() {
	Fraction F;
	F.setDenom(denom);
	F.setNum(num);
	int gc = F.gcd();

	F.setNum(F.getNum() / gc);
	F.setDenom(F.getDenom() / gc);

	return F;
}
Fraction Fraction::add(const Fraction& F) const{

	Fraction result;


	result.denom = denom * F.denom;
	result.num = num * F.denom + denom * F.num;


	return result;

}

ArrayOfFractions::ArrayOfFractions(){
	srand(time(NULL));

	for(int i=0; i < 10; i++){
		A[i].setNum(rand()% 9 +1);
		A[i].setDenom(rand()% 9 +1);
	}
}

void ArrayOfFractions::print(){
	for(int i=0; i < 10; i++){
		A[i].print();
		cout << endl;
	}
}

void ArrayOfFractions::sortAscending(){
	float m[10];
	Fraction tempF;
	float temp;
	
	for(int j=0; j<10; j++){
		m[j] = static_cast<float>(A[j].getNum()) / static_cast<float>(A[j].getDenom());
	}
	
	
	for (int i =0; i<10; i++){
		for(int j=i+1; j<10; j++){
			if(m[i] > m[j]){
				temp = m[j];
				m[j]=m[i];
				m[i]=temp;
				tempF = A[j];
				A[j] = A[i];
				A[i] = tempF;
			}
		}
	}
}

Fraction ArrayOfFractions::min(){
	ArrayOfFractions::sortAscending();

	return A[0];
}

Fraction ArrayOfFractions::max(){
	ArrayOfFractions::sortAscending();

	return A[9];
}



Fraction ArrayOfFractions::sum(){
	Fraction sum;

	for(int i=0; i <10; i++){
		sum = A[i].add(sum);

	}
	sum = sum.reduce();
	return sum;
}

