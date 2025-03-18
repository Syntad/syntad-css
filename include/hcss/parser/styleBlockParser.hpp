#pragma once

#include "parser.hpp"

class StyleBlockParser : public Parser {
    public:
        StyleBlock parse();
        using Parser::Parser;
        
        Declaration consumeDeclaration();
        optional<AtRule> consumeAtRule();
    private:
        StyleBlock block;
};