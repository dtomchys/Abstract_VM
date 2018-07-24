//
// Created by Denys TOMCHYSHEN on 7/22/18.
//

#ifndef ABSTRACT_VM_PARSER_H
#define ABSTRACT_VM_PARSER_H


#include <string>
#include <regex>
#include <iostream>
#include "eOperationType.h"
#include "eOperandType.h"

static const size_t op_tab_size = 11;
static const std::string op_tab[11] = {"push", "pop", "dump", "assert", "add",
                                         "sub", "mul", "div", "mod", "print", "exit"};
static const size_t type_tab_size = 5;
static const std::string type_tab[5] = {"int8", "int16", "int32", "float", "double"};
class Parser {
public:
    Parser();
    Parser(std::string str);
    Parser(Parser const &obj);
    Parser& operator=(Parser const &obj);
    ~Parser();

    eOperationType      get_op();
    eOperandType get_type();
    std::string         get_value();
private:
    eOperationType op;
    eOperandType   type;
    std::string    value;
};


#endif //ABSTRACT_VM_PARSER_H
