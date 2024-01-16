#include <iostream>
#include <string>

class EducationalInstitute {
public:
    EducationalInstitute(const std::string& name) : name(name) {}
    /* virtual function which will be called in child classes */
    virtual void show_info_about_institute() = 0;

    /* virtual function for overloading threads and operators
     *
     * виртуальные функции для перегрузки потоков нужны для ввода данных объекта из потока
     * считываем данные из потока in и сохранили в поле name
     * или вывели данные в поток out
     *
     * write_info — у нас тут ссылка на входной поток, чтоб обеспечить ввод данных в объект
     * в write_info реализации мы считали данные из потока и сохранили в поле name
     *
     * read_info — ссылка на поток вывода, чтоб сделать вывод данных
     * в read_info реализации мы выводим данные в поток out
     *
     * */
    virtual void write_info(std::istream& in) = 0;
    virtual void read_info(std::ostream& out) = 0;

    EducationalInstitute(const EducationalInstitute& other) : name(other.name) {}

    /*
     * here we doing overload for operator =
     */
    EducationalInstitute& operator=(const EducationalInstitute& other) {
        if (this != &other) {
            name = other.name;
        }

        return *this;
    }

    /* виртуальный деструктор нужен, чтоб при очистке памяти через указатель
     * вызвался не только деструктор базового класса, но и производного
     *
     * ПРИМЕР:
     * Base* obj = new Derived();
     * delete obj;
     *
     * вот чтоб тут вызвался деструктор не только у базового класса но и у производного,
     * при удалении через указатель на базовый (мы виртуалим деструктор)
     *
     * */
    virtual ~EducationalInstitute() {}

protected:
    std::string name;
};

class PreScholarInstitute : virtual public EducationalInstitute {
public:
    PreScholarInstitute(const std::string& name) : EducationalInstitute(name) {}

    void show_info_about_institute() override
    {
        std::cout << "PRESCHOOL EDUCATIONAL INSTITUTE: " << this->name << std::endl;
    }

    void write_info(std::istream& in) override
    {
        in >> name;
    }

    void read_info(std::ostream& out) override
    {
        out << "PRESCHOOL EDUCATIONAL INSTITUTE: " << name;
    }
};

class MediumEducationInstitute : virtual public EducationalInstitute {
public:
    MediumEducationInstitute(const std::string& name) : EducationalInstitute(name) {}

    void show_info_about_institute() override
    {
        std::cout << "THIS IS MEDIUM EDUCATIONAL INSTITUTE: " << this->name << std::endl;
    }

    void write_info(std::istream& in) override
    {
        in >> name;
    }

    void read_info(std::ostream& out) override
    {
        out << "THIS IS MEDIUM EDUCATIONAL INSTITUTE " << name;
    }
};

class HigherEducationInstitution : virtual public EducationalInstitute {
public:
    HigherEducationInstitution(const std::string& name) : EducationalInstitute(name) {}

    void show_info_about_institute() override
    {
        std::cout << "THIS IS HIGHER EDUCATIONAL INSTITUTE: " << this->name << std::endl;
    }

    void write_info(std::istream& in) override
    {
        in >> name;
    }

    void read_info(std::ostream& out) override
    {
        out << "THIS IS HIGHER EDUCATIONAL INSTITUTE: " << name;
    }
};

int
main() {
    PreScholarInstitute preSchool("KINDERGARTEN");
    MediumEducationInstitute mediumSchool("LYCEUM");
    HigherEducationInstitution superiorEducation("UNIVERSITY");

    std::cout << "Enter information for PreScholarInstitute (KINDERGARTEN): ";
    preSchool.write_info(std::cin);

    std::cout << "Enter information for MediumEducationInstitute (LYCEUM): ";
    mediumSchool.write_info(std::cin);

    std::cout << "Enter information for HigherEducationInstitution (UNIVERSITY): ";
    superiorEducation.write_info(std::cin);

    std::cout << "Displaying information for all institutes:" << std::endl;

    std::cout << "1. ";
    preSchool.show_info_about_institute();std::cout << "2. ";
    mediumSchool.show_info_about_institute();

    std::cout << "3. ";
    superiorEducation.show_info_about_institute();

    return EXIT_SUCCESS;
}