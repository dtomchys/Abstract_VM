#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "VirtMachine.h"

int main(int argc, char **argv)
{
//    std :: string s;
//    Lexer lex;
//    Parser par;
//    VirtMachine vm();
//
//    try {
//        if (argc == 1)
//            lex = Lexer();
//        else
//            lex = Lexer(s = std :: string (argv[argc - 1]));
//        lex.get_fd().is_open() ? lex.read(lex.get_fd()) : lex.read(std::cin);
//        for (size_t i = 0; i < lex.get_size(); ++i) {
//            par = Parser(lex.get_command());
//            std::cout << par.get_op() << " " << par.get_type() << " " << par.get_value() << std::endl;
//        }
//    } catch (std :: exception &ex) {
//        std :: cout << ex.what() << std :: endl;
//    }
    FactoryOperand maker;
    IOperand *a;
    a = maker.createOperand(INT8, "3");
    std::cout << a->toString() << std::endl;
    IOperand *b;
    b = maker.createOperand(FLOAT, "127.2");
    std::cout << b->toString() << std::endl;
    std::cout << (*b / *a)->toString() << std::endl;

}
