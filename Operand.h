//
// Created by Denys TOMCHYSHEN on 7/23/18.
//

#ifndef ABSTRACT_VM_OPERAND_H
#define ABSTRACT_VM_OPERAND_H

#include <iostream>
#include "sstream"
#include "IOperand.h"
#include "FactoryOperand.h"

template <typename T>
class Operand : public IOperand {
public:
    Operand<T>(eOperandType type, T value) : type(type), value(value) {
//        this->str = std::to_string(this->value);
        std::stringstream ss;
        ss << this->value;
        this->str = ss.str();
    };
    Operand<T>(Operand<T> const & obj);
    Operand<T> &operator=(Operand<T> const & obj);
    ~Operand<T>(){};

    int             getPrecision() const {
        return (int)this->type;
    };
    eOperandType    getType() const {
        return this->type;
    };

    IOperand const *operator+(IOperand const &rhs) const {
        eOperandType max = this->type > rhs.getType() ? this->type : rhs.getType();
        double tmp = this->value + std::stod(rhs.toString());
        std::string res = max > 3 ? std::to_string(tmp) : std::to_string((int)tmp);
        FactoryOperand *creator = new FactoryOperand();
        IOperand *new_obj = creator->createOperand(max, res);
        return new_obj;
    };
    IOperand const *operator-(IOperand const &rhs) const {
        eOperandType max = this->type > rhs.getType() ? this->type : rhs.getType();
        double tmp = this->value - std::stod(rhs.toString());
        std::string res = max > 3 ? std::to_string(tmp) : std::to_string((int)tmp);
        FactoryOperand *creator = new FactoryOperand();
        IOperand *new_obj = creator->createOperand(max, res);
        delete creator;
        return new_obj;
    };
    IOperand const *operator*(IOperand const &rhs) const {
        eOperandType max = this->type > rhs.getType() ? this->type : rhs.getType();
        double tmp = this->value - std::stod(rhs.toString());
        std::string res = max > 3 ? std::to_string(tmp) : std::to_string((int)tmp);
        FactoryOperand *creator = new FactoryOperand();
        IOperand *new_obj = creator->createOperand(max, res);
        delete creator;
        return new_obj;
    };
    IOperand const *operator/(IOperand const &rhs) const {
        eOperandType max = this->type > rhs.getType() ? this->type : rhs.getType();
        if(rhs.toString() == "0")
            throw std::invalid_argument("Division by 0");
        double tmp = this->value / std::stod(rhs.toString());
        std::string res = max > 3 ? std::to_string(tmp) : std::to_string((int)tmp);
        FactoryOperand *creator = new FactoryOperand();
        IOperand *new_obj = creator->createOperand(max, res);
        delete creator;
        return new_obj;
    };
    IOperand const *operator%(IOperand const &rhs) const {
        eOperandType max = this->type > rhs.getType() ? this->type : rhs.getType();
        if(rhs.toString() == "0")
            throw std::invalid_argument("Modulo by 0");
        long tmp = (long)this->value % std::stol(rhs.toString());
        std::string res = max > 3 ? std::to_string(tmp) : std::to_string((int)tmp);
        FactoryOperand *creator = new FactoryOperand();
        IOperand *new_obj = creator->createOperand(max, res);
        delete creator;
        return new_obj;
    };

    std::string const & toString() const{
        return this->str;
    };
private:
    eOperandType type;
    T            value;
    std::string str;
};



#endif //ABSTRACT_VM_OPERAND_H
