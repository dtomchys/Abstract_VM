//
// Created by Denys TOMCHYSHEN on 7/23/18.
//

#ifndef ABSTRACT_VM_FACTORYOPERAND_H
#define ABSTRACT_VM_FACTORYOPERAND_H

#include "IOperand.h"

class FactoryOperand {
public:
    FactoryOperand();
    ~FactoryOperand();

    IOperand *createOperand(eOperandType type, std::string const & value ) const;
private:
    IOperand const *createInt8( std::string const & value ) const;
    IOperand const *createInt16( std::string const & value ) const;
    IOperand const *createInt32( std::string const & value ) const;
    IOperand const *createFloat( std::string const & value ) const;
    IOperand const *createDouble( std::string const & value ) const;
};


#endif //ABSTRACT_VM_FACTORYOPERAND_H
