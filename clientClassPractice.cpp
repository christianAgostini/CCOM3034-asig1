#include <iostream>
#include <algorithm>
#include "classPractice.h"
#include "classPractice.cpp"
 
using namespace std;


void sortArray(Fraction n[]){

float m[10];
	Fraction tempF;
	float temp;
	
	for(int j=0; j<10; j++){
		m[j] = static_cast<float>(n[j].getNum()) / static_cast<float>(n[j].getDenom());
	}
	
	
	for (int i =0; i<10; i++){
		for(int j=i+1; j<10; j++){
			if(m[i] > m[j]){
				temp = m[j];
				m[j]=m[i];
				m[i]=temp;
				tempF = n[j];
				n[j] = n[i];
				n[i] = tempF;
			}
		}
	}

     float test;
    
	for(int i=0; i<10; i++){
		cout << endl;
		n[i].fracPrint();
		cout << " ";
	  
	}

}

int main(){
	Fraction frac1 , frac2, frac3;
	
	Fraction sumaFrac[10];

	srand(time(NULL));

	for(int i=0; i < 10; i++){
		sumaFrac[i].setNum(rand()% 9 +1);
		sumaFrac[i].setDenom(rand()% 9 +1);
	}


	frac1.setNum(7);
	frac1.setDenom(4);

	frac2.setNum(2);
	frac2.setDenom(4);


	frac3 = frac1.div(frac2);

	frac3 = frac3.reduce(frac3);

	frac3.fracPrint();

	frac1.gt(frac2);

	cout << endl << "Before sorting: " << endl;
	for(int i=0; i<10; i++){
		cout << endl;
		sumaFrac[i].fracPrint();
		cout << " ";
	}
	
    cout << endl; 
	cout << endl << "After sorting: " << endl;

	sortArray(sumaFrac);
    cout << endl;



	return 0;
}
