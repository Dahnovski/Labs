/*a) STRUCTURA CARTE 
 
 1) создали структуру Книга и определили данные связанные  с ней
 2) в конструкторе выделили память для хранения строк и скопировали
    их чтоб сохранить их на протяжении всего срока жизни экземпляра
    копировали данные в динамически выделенную память (кучу, потому что размер строки зависит от названия, издательства и тд)
    (потому что данные на стеке могут стереться после выхода из области видимости)
 3) в деструкторе освободили память
 4) определили методы: showInfoAboutBook() показываем информацию о книге
                       isEqual() сравнениваем название и таким образом мы производим поиск
 
 */

#include <iostream>
#include <cstring>

struct Book {
    char*       title;
    char*       author;
    char*       publisher;
    int         pages;
    short       year;


    Book(const char* t, const char* a,
         const char* pbs, int pgs, short yr)
    {
        title = new char[strlen(t) + 1];
        strcpy(title, t);

        author = new char[strlen(a) + 1];
        strcpy(author, a);

        publisher = new char[strlen(pbs) + 1];
        strcpy(publisher, pbs);

        pages = pgs;
        year = yr;
    }


    ~Book()
    {
        delete[] title;
        delete[] author;
        delete[] publisher;
    }

    void showInfoAboutBook()
    {
        std::cout << "NAME: "                   <<  title        <<     std::endl;
        std::cout << "AUTHOR: "                 <<  author       <<     std::endl;
        std::cout << "PUBLISHER: "              <<  publisher    <<     std::endl;
        std::cout << "QUANTITY OF PAGES: "      <<  pages        <<     std::endl;
        std::cout << "YEAR OF PUBLISHING: "     <<  year         <<     std::endl;
    }

    /* comparing by name and name of author (if both are equal -> returns true) */
    bool isEqual(const char* t, const char* a)
    {
        return (strcmp(title, t) == 0 && (strcmp(author, a) == 0));
    }
};

int
main(void)
{
    /* тут я создал объект на стеке */
    Book book1("Moby-Dick", "Herman Melville", "Falcone", 457, 1851);
    Book book2("Harry Potter", "J.K. Rolling", "Phoenix", 555, 2003);

    /* output info about books */
    book1.showInfoAboutBook();
    std::cout << std::endl;
    book2.showInfoAboutBook();
    std::cout << std::endl;

    /* caution book by name*/
    const char* searchByTitle = "Moby-Dick";
    const char* searchByAuthor = "Herman Melville";

    /*checking result of finding*/
    if(book1.isEqual(searchByTitle, searchByAuthor)) {
        std::cout << "BOOK WAS FOUND!" << std::endl;
    } else {
        std::cout << "BOOK WAS NOT FOUND!!!" << std:: endl;
    }

    return 0;
}