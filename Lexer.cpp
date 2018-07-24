//
// Created by Denys TOMCHYSHEN on 7/18/18.
//

#include "Lexer.h"


Lexer::Lexer(Lexer const &obj) {
    this->lst = obj.lst;
    this->cur_command = obj.cur_command;
    this->size = obj.size;
}

Lexer::Lexer() : cur_command(0), size(0){
    return ;
}

Lexer &Lexer::operator=(Lexer const &obj){
    if (this != &obj)
    {
        this->lst = obj.lst;
        this->cur_command = obj.cur_command;
        this->size = obj.size;
    }
    return *this;
}

Lexer::Lexer(std::string &std) : cur_command(0), size(0) {
    if (std.length()) {
        fd.open(std);
        if (!fd.is_open())
            throw std :: invalid_argument ("The file can't be open");
    }
}

void Lexer::check(std::string &str) {
    std::cmatch res;
    std::regex reg("(push|assert) (int(8|16|32)\\([-\\+]?\\d+\\)|"
                           "(double|float)\\([-\\+]?\\d+\\.\\d+\\))[ \\s]*?"
                           "|pop|dump|add|sub|mul|div|mod|print|exit");
    if(std::regex_match(str.c_str(), res, reg))
         return ;
    else
        throw std::invalid_argument("Invalid command");
//    for (int i = 0; i < res.size(); ++i) {
//        std::cout << res[i] << std::endl;
//    }
}

std::ifstream &Lexer::get_fd() {
    return this->fd;
}

void Lexer::read(std::ifstream &fd) {
    std::string str;
    while (42) {
        if (!fd)
            throw std::invalid_argument("No exit in the file!");
        getline(fd, str);
        this->check(str);
        this->size++;
        this->lst.push_back(str);
        if (!str.compare("exit"))
            break;
    }
}

void Lexer::read(std::istream &fd) {
    std::string str;
    while (1) {
        getline(fd, str);
        if (!str.compare(";;"))
            break;
        this->check(str);
        this->size++;
        this->lst.push_back(str);
    }
}

Lexer::~Lexer() {
    return ;
}

std::string Lexer::get_command() {
    auto it = this->lst.begin();
    int i;

    for (i = 0; i < this->cur_command; ++i) {
        if(it == this->lst.end())
            break;
        it++;
    }
    this->cur_command++;
    if(it == this->lst.end() && i < this->cur_command) {
        this->cur_command = 0;
        return std::string();
    }
    else
        return *it;
}

size_t &Lexer::get_size() {
    return this->size;
}

