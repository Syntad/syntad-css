#pragma once

#include <variant>
#include <hcss/lexer/token.hpp>
#include <hcss/util/util.hpp>

class AtRule;
class FunctionCall;
class QualifiedRule;
class SimpleBlock;
class StyleRule;

using SyntaxNode = std::variant<std::monostate, AtRule, FunctionCall, QualifiedRule, SimpleBlock, StyleRule>;
using ComponentValue = variant_append<SyntaxNode, Token>;