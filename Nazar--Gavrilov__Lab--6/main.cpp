/*
 *
 * Полиморфизм. Виртуальные функции.
 * Задание: написать полиморфную реализацию расчета площади.
 *
 */

#include    <iostream>
#include    <cmath>

class Figure
{
public:
    virtual double calc_area() = 0;

    virtual ~Figure() {}
};

class Parallelepiped : public Figure
{
public:
    Parallelepiped(double _sideX, double _sideY)
                   : x(_sideX)
                   , y(_sideY)
    {
        std::cout << "Parallelepiped CTOR..." << std::endl;
    }

    double calc_area() override
    {
        return 6 * x * y;
    }

private:
    double x, y;
};

class Sphere : public Figure
{
public:
    Sphere(double _radius)
           : radius(_radius)
    {
        std::cout << "Sphere CTOR..." << std::endl;
    }

    double calc_area() override
    {
        return 4 * M_PI * radius * radius;
    }

private:
    double radius;
};

class Tetrahedron : public Figure
{
public:
    Tetrahedron(double _side)
                : side(_side)
    {
        std::cout << "Tetrahedron CTOR..." << std::endl;
    }

    double calc_area() override
    {
        return side * side * sqrt(3.0);
    }

private:
    double side;
};

int main()
{
    Figure* f3 = new Parallelepiped(3.0, 4.0);
    f3->calc_area();

    Figure* f1;
    std::cout << "Address: " << f1 << std::endl;


    Parallelepiped parallelepiped(3.0, 4.0);
    std::cout << "Area of parallelepiped: " << parallelepiped.calc_area() << std::endl;

    Sphere sphere(5.0);
    std::cout << "Area of sphere: " << sphere.calc_area() << std::endl;

    Tetrahedron tetrahedron(4.0);
    std::cout << "Area of tetrahedron: " << tetrahedron.calc_area() << std::endl;

    return EXIT_SUCCESS;
}


