//
// Created by Denys TOMCHYSHEN on 7/23/18.
//


#include "Operand.h"

template<typename T>
Operand<T>::Operand(Operand<T> const &obj) : str(std::to_string(value)){
    this->value = obj.value;
    this->type = obj.type;
}

template<typename T>
Operand<T> &Operand<T>::operator=(Operand<T> const &obj) {
    if(this != &obj) {
        this->type = obj.type;
        this->value = obj.value;
        this->str = std::to_string(obj.value);
    }
    return *this;
}
