/*
 *
 * a) Создать иерархию наследования: удочка, телескоп - телескопическая удочка. (тут просто множественное наследование)
 *
 */

#include <iostream>
#include <string>

class FishingRod
{
public:
    FishingRod(const std::string& _name) : name(_name)
    {
        std::cout << "Fishing rod CTOR" << std::endl;
    }

    void using_rod() const
    {
        std::cout << "Fishing process with rod..." << std::endl;
    }

private:
    std::string     name;
};

class Telescope
{
public:
    Telescope(short _zoom) : zoom(_zoom)
    {
        std::cout << "Telescope CTOR" << std::endl;
    }

    void using_telescope() const
    {
        std::cout << "Zooming with telescope..." << std::endl;
    }

private:
    short           zoom;
};

class TelescopicRod : public FishingRod, public Telescope
{
public:
    TelescopicRod() {}
    TelescopicRod(const std::string& _name, short _zoom)
            : FishingRod(_name)
            , Telescope(_zoom)
    {
        std::cout << "TelescopicRod CTOR" << std::endl;
    }

    void extend_telescopic_fishing_rod() const
    {
        std::cout << "Extending telescopic fishing rod..." << std::endl;
    }

};

int main()
{
    TelescopicRod telescopic_rod("Raptor", 5);

    telescopic_rod.using_rod();
    telescopic_rod.using_telescope();
    telescopic_rod.extend_telescopic_fishing_rod();

    return EXIT_SUCCESS;
}