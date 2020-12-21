#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
namespace prog3_3 {

	class Set {
	private:
		int size;
		double arr[11];
		const int max = 11;
	public:
		Set();
		Set(double);
		Set(const double*);
		Set(const Set&);//копирующий
		


		void setSize(int);
		void FindMax() const {
			double a = 0, b;
			int k = 0;

			for (int i = 0; i < max; i++) {
				if (arr[i] < 0)
					b = arr[i] * (-1);
				else
					b = arr[i];
				if (b >= a) {
					a = b;
					k = i;
				}
			}
				std::cout << "max el =  " << arr[k];
		};

		int getSize() const { return size; }
		void getARR()  const { 
			for (int i = 0; i < max; i++)
			std::cout << " " << this->arr[i];
			std::cout << std::endl; 
		}


		Set& operator += (const double);
		friend Set operator + (const Set&, Set&);
		friend Set operator * (const Set&, Set&);
		friend Set operator - (Set&, Set&);
		Set& operator = (const Set& other);
		friend std::ostream& operator << (std::ostream&, const Set&);
		friend std::istream& operator >> (std::istream&, Set&);


		int add_el(const double);
	};
	double getNaturalIntd(double a);
	int getNaturalInt0(int a);
	int enternumber(double a);
}