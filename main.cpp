#include <iostream>
#include "Lexer.h"

int main(int argc, char **argv)
{
    Lexer lex;
    std :: string s;
    try {
        if (argc == 1)
            lex = Lexer();
        else
            lex = Lexer(s = std :: string (argv[argc - 1]));
        lex.get_fd().is_open() ? lex.read(lex.get_fd()) : lex.read(std::cin);
    } catch (std :: exception &ex) {
        std :: cout << ex.what() << std :: endl;
    }
}
