#pragma once

#include <memory>

#include "query_processing_system/query_evaluator/design_entity_visitor/interfaces/visit/IVisitsProcedure.h"
#include "query_processing_system/query_evaluator/design_entity_visitor/interfaces/visit/IVisitsVariable.h"
#include \
    "query_processing_system/query_evaluator/design_entity_visitor/interfaces/relationships/EntityEntityRelationship.h"
#include "query_processing_system/query_evaluator/storage_reader/IUsesProcedureReader.h"

class UsesProcedureVisitor : public IVisitsProcedure, public IVisitsVariable, public EntityEntityRelationship {
private:
    std::shared_ptr<IUsesProcedureReader> usesReader;
public:
    explicit UsesProcedureVisitor(const std::shared_ptr<IUsesProcedureReader>& usesReader);

    void visit(const std::shared_ptr<ProcedureSynonym>& statement) override;
    void visit(const std::shared_ptr<ProcedureName>& statement) override;
    void visit(const std::shared_ptr<ProcedureWildcard>& statement) override;

    void visit(const std::shared_ptr<VariableSynonym>& variable) override;
    void visit(const std::shared_ptr<VariableName>& variable) override;
    void visit(const std::shared_ptr<VariableWildcard>& variable) override;
};
