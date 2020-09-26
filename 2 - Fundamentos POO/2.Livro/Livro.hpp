#ifndef Livro_hpp
#define Livro_hpp

#include <iostream>

class Livro
{
private:
    /* data */
    std::string ISBN;
    std::string titulo;
    std::string autor;

    bool emprestado = false;

public:
    Livro(std::string titulo,std::string autor,std::string num0,std::string num1,std::string num2,std::string dig);
    ~Livro();

    bool getEmprestimo();
    void setEmprestimo(bool emprestado);

    std::string getTitulo();
    void setTitulo(std::string titulo);

    std::string getAutor();
    void setAutor(std::string autor);

    std::string getISBN();
    void setISBN(std::string codigo);

    bool valida_ISBN(std::string str0,std::string str1,std::string str2,std::string dig);

    bool valida_numero (std::string str);
};

#endif

