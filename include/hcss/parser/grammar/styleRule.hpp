#pragma once

#include <utility>

#include "selector.hpp"
#include "styleBlock.hpp"

struct StyleRule {
    ComplexSelectorList selectors;
    StyleBlock block;
};