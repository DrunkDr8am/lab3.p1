#define _CRT_SECURE_NO_WARNINGS
#include "Set.h"

using namespace prog3_3;

int main() {
        Set S1(5), S2(-3), S3;
        char n;
        double d = 0;

        std::cout << "1. Push into stack: max size = 11 " << std::endl;
  
        std::cout << "Enter nums for set1: ";
        std::cin >> S1;
     
        std::cout << "Current size = " << S1.getSize() << std::endl << "; In VEC : \n";
        S1.getARR();
        std::cout << std::endl << std::endl;                

            std::cout << "2. Push into local tmp VEC: \n";
            std::cout << "Enter nums for set2: ";
            std::cin >> S2;
            std::cout << "In tmp VEC: \n";
            S2.getARR();
            std::cout << std::endl << std::endl;


            std::cout << "3. Copying from new VEC into tmp VEC: \n";       
            S3 = S2;
        
        std::cout << std::endl << "In new VEC: \n";
        S3.getARR();
        std::cout << std::endl;
        std::cout << std::endl << "In tmp VEC: \n";
        S2.getARR();
        std::cout << std::endl << std::endl;

        std::cout << "4. tmp VEC + VEC: \n";
        S3 = S1 + S2;
        std::cout << std::endl << "In new VEC: \n";
        S3.getARR();
        std::cout << std::endl << std::endl;

        std::cout << "5. tmp VEC - VEC:\n";
        S3 = S1 - S2;
        std::cout << std::endl << "In new VEC: \n";
        S3.getARR();
        std::cout << std::endl << std::endl;

        std::cout << "6.  tmp VEC * VEC: \n";
        S3 = S1 * S2;
        std::cout << std::endl << "In new VEC: \n";
        S3.getARR();

        std::cout << std::endl << std::endl;
        std::cout << "7.  VEC + one vector: \n"; // плюс еденичный вектор. например (3)
        std::cout << "enter the number: \n";
        d = getNaturalIntd(d);
        Set S4(d);
        S1 = S1 + S4;
        std::cout << std::endl << "In  VEC: \n";
        S1.getARR();
        std::cout << std::endl << std::endl;

        std::cout << "8.  VEC + el: \n";
        do {
            std::cout << "do you want to ad element to VEC? y/n";
            std::cin >> n;
            if (n != 'n')
                d = getNaturalIntd(d);
                S1.add_el(d);
                std::cout << std::endl << "In  VEC: \n";
                S1.getARR();
                std::cout << std::endl << std::endl;
        } while (n != 'n');
        
        
        std::cout << std::endl << std::endl;
        std::cout << "9.  max el: \n";
        S1.FindMax();
        std::cout << std::endl << std::endl;

        return 0;
    }
       