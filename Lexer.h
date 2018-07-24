//
// Created by Denys TOMCHYSHEN on 7/18/18.
//

#ifndef ABSTRACT_VM_LEXER_H
#define ABSTRACT_VM_LEXER_H

#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <regex>

class Lexer {
public:
    Lexer();
    Lexer(std :: string &std);
    Lexer(Lexer const &obj);
    Lexer& operator=(Lexer const &obj);
    ~Lexer();

    void    read(std :: istream &fd);
    void    read(std :: ifstream &fd);
    void    check(std :: string &str);

    std::ifstream&  get_fd();
    size_t&         get_size();
    std::string     get_command();
private:
    std::list<std::string>  lst;
    std::ifstream           fd;
    size_t                  size;
    size_t                  cur_command;
};


#endif //ABSTRACT_VM_LEXER_H
