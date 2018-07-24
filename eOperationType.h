//
// Created by Denys TOMCHYSHEN on 7/22/18.
//

#ifndef ABSTRACT_VM_EOPERATIONTYPE_H
#define ABSTRACT_VM_EOPERATIONTYPE_H


enum    eOperationType{
    PUSH = 0,
    POP,
    DUMP,
    ASSERT,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    PRINT,
    EXIT,
    NON
};
#endif //ABSTRACT_VM_EOPERATIONTYPE_H
