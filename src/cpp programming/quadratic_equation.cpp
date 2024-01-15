#include <iostream>
#include <cmath>

void quadraticEquation(double a, double b, double c)
{
    double x1;
    double x2;
    double delta;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                std::cout << "PT co vo so nghiem !\n";
                return;
            }
            std::cout << "PT vo nghiem!\n";
            return;
        }
        std::cout << "PT co nghiem duy nhat -c/b = " << -c / b << std::endl;
        return;
    }

    delta = pow(b, 2) - 4 * a * c;

    if (delta < 0)
    {
        std::cout << "PT vo nghiem!\n";
        return;
    }

    if (delta == 0)
    {
        x1 = -b / (2 * a);
        std::cout << "PT co nghiem kep x1 = x2 = " << x1 << std::endl;
        return;
    }

    if (delta > 0)
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        std::cout << "PT co 2 nghiem phan biet:\n";
        std::cout << "x1 = " << x1 << std::endl;
        std::cout << "x2 = " << x2 << std::endl;
    }

    return;
}

double PT_bac_nhat(double a, double b)
{
}

int main()
{
    double a, b, c;
    std::string choice;

    do
    {
        std::cout << "Nhap he so a, b, c: ";
        std::cin >> a >> b >> c;
        quadraticEquation(a, b, c);
        std::cout << "Ban co muon tiep tuc khong (y/n)?";
        std::cin >> choice;
    } while (choice == "y");

    return 0;
}