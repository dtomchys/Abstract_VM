//
// Created by Denys TOMCHYSHEN on 7/23/18.
//

#include "FactoryOperand.h"
#include "Operand.h"

FactoryOperand::FactoryOperand() {
    return ;
}

FactoryOperand::~FactoryOperand() {
    return ;
}

IOperand * FactoryOperand::createOperand(eOperandType type, std::string const &value) const {
    switch(type) {
        case INT8:
            return const_cast<IOperand *>(createInt8(value));
        case INT16:
            return const_cast<IOperand *>(createInt16(value));
        case INT32:
            return const_cast<IOperand *>(createInt32(value));
        case FLOAT:
            return const_cast<IOperand *>(createFloat(value));
        case DOUBLE:
            return const_cast<IOperand *>(createDouble(value));
        case NONE:
            return const_cast<IOperand *>(createInt8(value));
    }
}

IOperand const *FactoryOperand::createInt8(std::string const &value) const {
    int a = std::stoi(value);
    if (a > INT8_MAX)
        throw std::overflow_error("Overflow INT8");
    else if (a < INT8_MIN)
        throw std::underflow_error("Underflow INT8");
    return new Operand<int8_t>(INT8, (int8_t)a);
}

IOperand const *FactoryOperand::createInt16(std::string const &value) const {
    int a = std::stoi(value);
    if (a > INT16_MAX)
        throw std::overflow_error("Overflow INT16");
    else if (a < INT16_MIN)
        throw std::underflow_error("Underflow INT16");
    return new Operand<int16_t>(INT16, (int16_t)a);
}

IOperand const *FactoryOperand::createInt32(std::string const &value) const {
    long long a = std::stol(value);
    if (a > INT32_MAX)
        throw std::overflow_error("Overflow INT32");
    else if (a < INT32_MIN)
        throw std::underflow_error("Underflow INT32");
    return new Operand<int32_t>(INT32, (int32_t)a);
}

IOperand const *FactoryOperand::createFloat(std::string const &value) const {
    float a = std::stof(value);
    if (a > 0 && value.c_str()[0] == '-') {
        throw std::overflow_error("Overflow Float");
    }
    else if (a < 0 && value.c_str()[0] != '-') {
        throw std::underflow_error("Underflow Float");
    }
    return new Operand<float>(FLOAT, a);
}

IOperand const *FactoryOperand::createDouble(std::string const &value) const {
    double a = std::stod(value);
    if (a > 0 && value.c_str()[0] == '-')
        throw std::overflow_error("Overflow Double");
    else if (a < 0 && value.c_str()[0] != '-')
        throw std::underflow_error("Underflow Double");
    return new Operand<double>(DOUBLE, a);
}

