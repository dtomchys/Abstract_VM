//
// Created by Denys TOMCHYSHEN on 7/18/18.
//

#include "Lexer.h"


Lexer::Lexer(Lexer const &obj) {
    this->lst = obj.lst;
}

Lexer::Lexer() {

    return ;
}

Lexer &Lexer::operator=(Lexer const &obj){
    if (this != &obj)
    {
        this->lst = obj.lst;
    }
    return *this;
}

Lexer::Lexer(std::string &std) {
    if (std.length()) {
        fd.open(std);
        if (!fd.is_open())
            throw std :: invalid_argument ("The file can't be open");
    }
}

void Lexer::check(std::string &str) {

}

std::ifstream &Lexer::get_fd() {
    return this->fd;
}

void Lexer::read(std::ifstream &fd) {
    std::string str;
    while (42) {
        if (!str.compare(";;"))
            break;
        getline(fd, str);
        this->check(str);
        this->lst.push_back(str);
    }
}

void Lexer::read(std::istream &fd) {
    std::string str;
    while (1) {
        if (!str.compare(";;"))
            break;
        getline(fd, str);
        this->check(str);
        this->lst.push_back(str);
    }
}

Lexer::~Lexer() {
    return ;
}

