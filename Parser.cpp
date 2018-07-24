//
// Created by Denys TOMCHYSHEN on 7/22/18.
//

#include "Parser.h"

Parser::Parser() : op(NON), type(NONE), value(""){
    return ;
}

Parser::Parser(std::string str) : op(NON), type(NONE), value(""){

    std::regex reg("(pop|dump|add|sub|mul|div|mod|print|exit|push|assert)"
                           "( (int8|int16|int32|float|double)\\((\\d+[.]?\\d+)\\))?");
    std::smatch res;
    std::regex_search(str, res, reg);
//    for (int i = 0; i < res.size(); ++i) {
//        std::cout << res[i] << std::endl;
//    }
    for (int j = 0; j < op_tab_size; ++j) {
        if(op_tab[j].compare(res[1]) == 0) {
            this->op = (eOperationType)j;
            if(j == 0 || j == 3) {
                for (int i = 0; i < type_tab_size; ++i) {
                    if(type_tab[i].compare(res[3]) == 0)
                    this->type = (eOperandType)i;
                }
                this->value = res[4];
            }
        }
    }
}

Parser::Parser(Parser const &obj) : op(obj.op), type(obj.type), value(obj.value){
    return ;
}

Parser &Parser::operator=(Parser const &obj) {
    if(this != &obj) {
        this->op = obj.op;
        this->type = obj.type;
        this->value = obj.value;
    }
    return *this;
}

Parser::~Parser() {
    return ;
}

eOperationType Parser::get_op() {
    return this->op;
}

eOperandType Parser::get_type() {
    return this->type;
}

std::string Parser::get_value() {
    return this->value;
}


