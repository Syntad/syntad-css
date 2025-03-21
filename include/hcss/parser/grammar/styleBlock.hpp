#pragma once

#include "../types.hpp"
#include <utility>
#include <vector>
#include <variant>
class StyleRule;

struct Declaration {
    Token name;
    Token colon;
    std::vector<ComponentValue> value;
    bool important;
};

using StyleBlockVariant = std::variant<std::monostate, Declaration, AtRule, QualifiedRule, StyleRule>;
using StyleBlock = std::vector<StyleBlockVariant>;