//
// Created by Denys TOMCHYSHEN on 7/23/18.
//

#ifndef ABSTRACT_VM_VIRTMACHINE_H
#define ABSTRACT_VM_VIRTMACHINE_H

#include <string>
#include <stack>
#include "eOperandType.h"
#include "eOperationType.h"
#include "IOperand.h"
#include "FactoryOperand.h"

class VirtMachine {
public:
    VirtMachine();
    VirtMachine(VirtMachine const &obj);
    VirtMachine &operator=(VirtMachine const &obj) const;
    ~VirtMachine();

    void    run(eOperationType op, eOperandType type = NONE, std::string str = 0);
private:
    void    push(eOperandType type, std::string value);
    void    pop();
    void    dump();
    void    assert(eOperandType type, std::string value);
    void    add();
    void    sub();
    void    mul();
    void    div();
    void    mod();
    void    print();
    void    exit();
    std::stack<IOperand*> stack;
};


#endif //ABSTRACT_VM_VIRTMACHINE_H
