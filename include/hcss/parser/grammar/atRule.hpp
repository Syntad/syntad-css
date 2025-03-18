#pragma once

#include "../types.hpp"
#include "simpleBlock.hpp"
#include <utility>
#include <vector>
#include <optional>

struct AtRule {
    Token name;
    std::vector<ComponentValue> prelude;
    std::optional<SimpleBlock> block;
};