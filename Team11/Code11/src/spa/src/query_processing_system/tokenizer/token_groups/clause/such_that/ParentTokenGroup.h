#pragma once

#include <string>
#include <memory>
#include <vector>
#include "query_processing_system/tokenizer/token_groups/clause/such_that/SuchThatTokenGroup.h"

class ParentTokenGroup : public SuchThatTokenGroup, public std::enable_shared_from_this<ParentTokenGroup> {
public:
    explicit ParentTokenGroup(const std::vector<std::shared_ptr<Token> >& tokenList) : SuchThatTokenGroup(tokenList) {
    }

    bool validateSyntax(TokenGroupSyntaxValidator& v) override;
    bool validateSemantics(TokenGroupSemanticValidator& v) override;
    void buildQuery(TokenGroupExtractor& v, Query& q) override;
};