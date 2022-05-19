#include <iostream>
#include "lab_polinom_C.h"



int main() {
    int n = 0, k = 0, u = 0;
    int *coef, *coef1;

    std::cout << "Введите степень первого многочлена \n";
    std::cin >> n;

    polinom p(n);
    coef = new int[n+1];
    for (int i = 0; i <= n; i++) {
        std::cout << "Коэффициент [" << i << "] ";
        std::cin>>coef[i];
    }
    p.push(n, coef);

    int m = 0;
    std::cout << "Введите степень второго многочлена \n";
    std::cin >> m;

    polinom s(m);
    coef1 = new int[n+1];
    for (int i = 0; i <= m; i++) {
        std::cout << "Коэффициент [" << i << "] ";
        std::cin>>coef1[i];
    }
    s.push(m, coef1);

    std::cout << "Первый многочлен " << p << '\n';
    std::cout << "Второй многочлен " << s << '\n';

//    std::cout << "Деление: \n";
    polinom x(p.get_degr() + s.get_degr());
    x = p * s;
    std::cout << "Произведение: " << x << '\n';

    std::cout << "НОД: \n";
    polinom y(p.get_degr() + s.get_degr());
    y = polinom::NOD(p, s);
    std::cout << "нод: " << y << '\n';

    std::cout << "НОК: \n";
    polinom c(p.get_degr() + s.get_degr());
    c = polinom::NOK(p, s);
    std::cout << "НОК: " << c << '\n';
}
