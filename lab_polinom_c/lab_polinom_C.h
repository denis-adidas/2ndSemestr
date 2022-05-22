//
// Created by Денис Адидас on 5/18/22.
//

#ifndef LAB_POLINOM_C_LAB_POLINOM_C_H
#define LAB_POLINOM_C_LAB_POLINOM_C_H
#include <iostream>;

class polinom {
protected:
    int degree;
    int* coef;
public:
polinom(){};
polinom(int count);
//~polinom(){delete[] coef; }
polinom operator/(polinom&);
polinom operator%(polinom&);
polinom operator*(polinom&);
polinom max_p(polinom& ob_1, polinom& ob_2);
//polinom operator=(polinom t);
int get_degr() { return degree;}
int push(int, int*);
static polinom& NOD(const polinom&, const polinom&);
static polinom& NOK(polinom&, polinom&);
friend std::ostream &operator<<(std::ostream &, polinom&);
};
#endif //LAB_POLINOM_C_LAB_POLINOM_C_H
