/*
 *
 * b) Создать иерархию наследования: объект - стержень, телескоп - телескопический стержень. (тут множественное + виртуальное)
 *
 */

#include    <iostream>
#include    <string>

class Object
{
public:
    Object(short _size_for_obj)
            : size(_size_for_obj)
    {
        std::cout << "Object CTOR" << std::endl;
    }

private:
    short       size;
};

class Rod : virtual public Object
{
public:
    Rod(short _size_for_rod, short _size_for_obj)
            : Object(_size_for_obj)
            , size(_size_for_rod)
    {
        std::cout << "Rod CTOR" << std::endl;
    }

private:
    short       size;
};

class Telescope : virtual public Object
{
public:
    Telescope(short _size_for_telescope, short _size_for_obj)
            : Object(_size_for_obj)
            , size(_size_for_telescope)
    {
        std::cout << "Telescope CTOR" << std::endl;
    }

private:
    short       size;
};

class TelescopicRod : public Rod, public Telescope
{
public:
    TelescopicRod(short _size_for_obj,
                  short _size_for_rod,
                  short _size_for_telescope,
                  short _size_for_telescopic_rod,
                  const std::string& _color_for_telescopic_rod)
            : Object(_size_for_obj)
            , Rod(_size_for_rod, _size_for_obj)
            , Telescope(_size_for_telescope, _size_for_obj)
            , size(_size_for_telescopic_rod)
            , color(_color_for_telescopic_rod)
    {
        std::cout << "Telescopic rod CTOR" << std::endl;
    }

    void get_info() const
    {
        std::cout << "Size: " << size   << std::endl;
        std::cout << "Color:" << color  << std::endl;
    }

private:
    short           size;
    std::string     color;
};

int
main()
{
    TelescopicRod tr(10, 25, 25, 30, "green");
    tr.get_info();

    return EXIT_SUCCESS;
}
