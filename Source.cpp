#define _CRT_SECURE_NO_WARNINGS
#include "Set.h"

namespace prog3_3 {

	Set::Set() : size(0), arr() {
		size = 0;
		//std::cout << "constructor for " << this << std::endl;
		for (int i = 0; i <= max - 1; i++)
			arr[i] = 0;
	}

	Set::Set(double el) {
		//std::cout << "constructor for " << this << std::endl;
		this->size = 1;
		for (int i = 0; i < 1; i++)
			arr[i] = el;
		for (int i = 1; i <= max-1; i++)
			arr[i] = 0;
	}

	Set::Set(const double* arr) : size(0) {
		//std::cout << "constructor for " << this << std::endl;
		for (this->size = 0; arr[this->size]; this->size++);
		//arr[this->size] = arr[this->size];
	}

	Set::Set(const Set& other) {
		//std::cout << "copy for   " << this << std::endl;
		for (int i = 0; i <= max; i++)
		{
			this->arr[i] = other.arr[i];
			
		};
		this->size = other.size;
	}



	void Set::setSize(int size) {
		this->size = size;
	}


	Set operator + (const Set& right, Set& left) {
		int i;
		double a;
		Set Str;
		if (right.size > left.size) {
			for (i = 0; i < right.size; i++)
			{
				if (right.size > left.size) {
					if (i + 1 > left.size)
						a = right.arr[i];
					else
						a = right.arr[i] + left.arr[i];
				}
				else
					a = right.arr[i] + left.arr[i];
				Str += a;
			}
		}
		else {
			for (i = 0; i < left.size; i++)
			{
				if (left.size > right.size) {
					if (i + 1 > right.size)
						a = left.arr[i];
					else
						a = left.arr[i] + right.arr[i];
				}
				else
					a = left.arr[i] + right.arr[i];
				Str += a;
			}
		}
		return Str;
	}

	Set& Set::operator += (const double a) {
		this->add_el(a);
		return *this;
	}

	Set operator * (const Set& right, Set& left) {
		Set Str;
		int i;
		double a;
		if (right.size > left.size) {
			for (i = 0; i < right.size; i++)
			{
				if (right.size > left.size) {
					if (i + 1 > left.size)
						a =  0;
					else
						a = right.arr[i] * left.arr[i];
				}
				else
					a = right.arr[i] * left.arr[i];
				Str += a;
			}
		}
		else {
			for (i = 0; i < left.size; i++)
			{
				if (left.size > right.size) {
					if (i + 1 > right.size)
						a =  0;
					else
						a = left.arr[i] * right.arr[i];
				}
				else
					a = left.arr[i] * right.arr[i];
				Str += a;
			}

		}
		return Str;
	}

	Set& Set::operator = (const Set& other) {
		int one, two;
		if (size != 0) {
			for (int i = 0; i <= max-1 ; i++)
				arr[i] = 0;
			size = 0;
		}
		one = this->size;
		for (int i = 0; i < other.size;  i++)
			this->add_el(other.arr[i]);
		two= other.size;
		if (one > two)
			size = one;
		else
			size = two;
		
				return *this;
	}

	Set operator - (Set& right, Set& left) {
		int i;
		double a;
		Set Str;
		if (right.size > left.size) {
			for (i = 0; i < right.size; i++)
			{
				if (right.size > left.size) {
					if (i + 1 > left.size)
						a = right.arr[i];
					else
						a = right.arr[i] - left.arr[i];
				}
				else
					a = right.arr[i] - left.arr[i];
				Str += a;
			}
		}
		else {
			for (i = 0; i < left.size; i++)
			{
				if (left.size > right.size) {
					if (i + 1 > right.size)
						a = left.arr[i];
					else
						a = left.arr[i] - right.arr[i];
				}
				else
					a = left.arr[i] - right.arr[i];
				Str += a;
			}
		}
		return Str;
	}

	std::ostream& operator << (std::ostream& s, const Set& other) {
		other.getARR();
		return s;
	}

	std::istream& operator >> (std::istream& s, Set& other) {
		try {
			int l = 0;
			double b = '\n';
			other.size = 0;
			std::cout << "how much elements: ";
			l = getNaturalInt0(l);
			for (int i = 0; i < l; ++i)
			{
				b = getNaturalIntd(b);
				other.add_el(b);
			}

			return s;
		}
		catch (std::exception& ex) {
			std::cout << ex.what();
			std::cin.ignore(INT_MAX, '\n');
			std::cin.clear();
		}
	}


	int Set::add_el(const double el) {
		if (size <= max - 1) {

			arr[size] = el;
			this->size++;
		}
		else {
			std::cout << "ERROR =) vector is full!" << std::endl;
		}
		return 0;
	}

	int getNaturalInt0(int a) {
		do {
			std::cin >> a;
			if (a == 0 || a < 0 || a > 11) {
				std::cout << "Error! Please, repeat your input: ";
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		} while (a == 0 || a < 0 || a > 11);
		return a;
	}

	double getNaturalIntd(double a) {
		std::cout << "enter el: ";
		while (!(std::cin >> a)) {
			std::cout << "error please reapit." << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');			
		}
		return a;
	}
}