//
// Created by Денис Адидас on 5/18/22.
//

#include "lab_polinom_C.h"

polinom::polinom(int count) {
    degree = count;
    coef = new int[degree+1];
}

int polinom::push(int n, int *k) {
    degree = n;
    coef = new int[degree+1];
    for (int i = n; i >= 0; i--) coef[i] = k[i];
    return 0;
}

std::ostream &operator<<(std::ostream &fo, polinom &o) {
    int f = 0;
    for (int i = o.degree; i >= 0; i--)
        if (o.coef[i] != 0) {
            if (f == 0) {
                if (i != 0) fo << o.coef[i] << "*x^" << i;
                else fo << o.coef[i];
                f++;
            } else {
                if (i != 0)
                    if (o.coef[i] > 0) fo << "+" << o.coef[i] << "*x^" << i;
                    else fo << o.coef[i] << "*x^" << i;
                else if (o.coef[i] > 0) fo << "+" << o.coef[i];
                else fo << o.coef[i];
                f++;
            }
        }
    if (f == 0) fo << 0;
    fo << std::endl;
    return fo;
}

//polinom polinom::operator=(polinom t)
//{
//    if (this == t)
//    {
//        return *this;
//    }
//    degree=t.degree;
//    for(int i=degree;i>=0;i--)
//        coef[i]=t.coef[i];
//    return *this;
//}

polinom polinom::operator /(polinom &ob) {

    bool inAlgoritm = true;
    polinom temp;
    polinom ob_1;
    polinom ob_2;
    polinom ob_4;

    temp.degree = degree - ob.degree;
    temp.coef = new int[temp.degree + 1];
    memset(temp.coef, 0, (temp.degree + 1) * sizeof(int));

    ob_1.degree = degree;
    ob_1.coef = new int[degree + 1];
    for (int i = degree; i >= 0; i--)
        ob_1.coef[i] = coef[i];

    ob_2.degree = ob.degree;
    ob_2.coef = new int[degree + 1];
    for (int i = ob.degree; i >= 0; i--)
        ob_2.coef[i] = ob.coef[i];

    ob_4.degree = ob_1.degree;
    ob_4.coef = new int[ob_1.degree + 1];

    int mult;
    int k = 0;
    int i, j;
    while (inAlgoritm)
    {
        for (int i = ob.degree; i >= 0; i--)
            ob_4.coef[i] = ob.coef[i];
        if (ob_2.degree < ob_1.degree) {
            for (i = ob_1.degree, j = ob_2.degree; i >= 0; i--, j--)
                if (j < 0)
                    ob_4.coef[i] = 0;
                else
                    ob_4.coef[i] = ob_2.coef[j];
        }

        mult = ob_1.coef[ob_1.degree] / ob_4.coef[ob_1.degree];

        temp.coef[temp.degree - k] = mult;
        k++;

        for (int i = 0; i <= ob_1.degree; i++)
            ob_4.coef[i] *= mult;

        for (int i = 0; i <= ob_1.degree; i++)
            ob_1.coef[i] -= ob_4.coef[i];

        ob_1.degree--;
        if (ob_2.degree > ob_1.degree)
            inAlgoritm = false;
    }
    return temp;
}

polinom polinom::operator %(polinom &ob) {

    bool inAlgoritm = true;
    polinom temp;
    polinom ob_1;
    polinom ob_2;
    polinom ob_4;

    temp.degree = degree - ob.degree;
    temp.coef = new int[temp.degree + 1];
    memset(temp.coef, 0, (temp.degree + 1) * sizeof(int));

    ob_1.degree = degree;
    ob_1.coef = new int[degree + 1];
    for (int i = degree; i >= 0; i--)
        ob_1.coef[i] = coef[i];

    ob_2.degree = ob.degree;
    ob_2.coef = new int[degree + 1];
    for (int i = ob.degree; i >= 0; i--)
        ob_2.coef[i] = ob.coef[i];

    ob_4.degree = ob_1.degree;
    ob_4.coef = new int[ob_1.degree + 1];

    int mult;
    int k = 0;
    int i, j;
    while (inAlgoritm)
    {
        for (int i = ob.degree; i >= 0; i--)
            ob_4.coef[i] = ob.coef[i];
        if (ob_2.degree < ob_1.degree) {
            for (i = ob_1.degree, j = ob_2.degree; i >= 0; i--, j--)
                if (j < 0)
                    ob_4.coef[i] = 0;
                else
                    ob_4.coef[i] = ob_2.coef[j];
        }

        mult = ob_1.coef[ob_1.degree] / ob_4.coef[ob_1.degree];

        temp.coef[temp.degree - k] = mult;
        k++;

        for (int i = 0; i <= ob_1.degree; i++)
            ob_4.coef[i] *= mult;

        for (int i = 0; i <= ob_1.degree; i++)
            ob_1.coef[i] -= ob_4.coef[i];

        ob_1.degree--;
        if (ob_2.degree > ob_1.degree)
            inAlgoritm = false;
    }
    return ob_1;
}

polinom polinom::operator *(polinom& ob) {

    polinom temp;
    temp.degree = degree + ob.degree;
    temp.coef = new int[temp.degree + 1];
    memset(temp.coef, 0, (temp.degree+1) * sizeof(int));

    for(int i=0; i<=degree; i++)
    {
        for(int j=0;j<=ob.degree;j++)
        {
            temp.coef[i+j] += coef[i]*ob.coef[j];
        }
    }
    return temp;
}

polinom& polinom::NOD(const polinom &ob_1, const polinom &ob_2) {

    polinom ob_3;
    polinom bigger;
    polinom small;

    if (ob_1.degree > ob_2.degree) {
        bigger = ob_1;
        small = ob_2;
    }
    else {
        bigger = ob_2;
        small = ob_1;
    }

    ob_3.degree = ob_1.degree;
    ob_3.coef = new int[ob_3.degree+1];
    memset(ob_3.coef, 0, (ob_3.degree + 1) * sizeof(int));


    while (ob_3.degree > 1) {
        ob_3 = bigger / small;
        if (ob_3.coef[0] == 0 && ob_3.degree == 0) {
            ob_3 = ob_2;
            break;
        }
        bigger = small;
        small = ob_3;
    }
    return ob_3;
}

polinom& polinom::NOK(polinom &ob_1, polinom &ob_2) {

    polinom temp;

    temp.degree = ob_1.degree + ob_2.degree;
    temp.coef= new int[temp.degree + 1];
    memset(temp.coef, 0, (temp.degree + 1) * sizeof(int));

    temp = (ob_1 * ob_2);
    ob_1 = NOD(ob_1, ob_2);
    temp = temp / ob_1;

    return temp;
}