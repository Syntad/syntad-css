#pragma once

#include "componentValueParser.hpp"
#include "types.hpp"
#include <map>

typedef struct Mixin {
    optional<FunctionDefinition> function;
    vector<ComponentValue> value = {};
} Mixin;

typedef struct Scope {
    Scope* parent;
    std::map<wstring, vector<ComponentValue>> variables, atRules;
    std::map<wstring, Mixin> mixins;
    std::vector<wstring> parameters;
    vector<ComponentValue>* findVariable(const wstring& name);
    vector<ComponentValue>* findAtRule(const wstring& name);
    Mixin* findMixin(const wstring& name);
    bool isParameter(const wstring& name);
} Scope;

class Parser : public ComponentValueParser {
    public:
        vector<SyntaxNode> parse();
        using ComponentValueParser::ComponentValueParser;

        virtual optional<AtRule> consumeAtRule();
        void consumeMixin();
        vector<vector<ComponentValue>> consumeCommaList();
        FunctionDefinition consumeFunctionDefinition();
        FunctionCall consumeFunctionCall();
        QualifiedRule consumeQualifiedRule();
        SimpleBlock consumeSimpleBlock();
        ComponentValue consumeComponentValue();
        void consumeComponentValue(vector<ComponentValue>& vec);
        vector<SyntaxNode> consumeRulesList();
        vector<ComponentValue> consumeValueList();
        bool consumeVariable();
    protected:
        vector<SyntaxNode> rules;
        Scope scope = {};
        bool top = true;
};