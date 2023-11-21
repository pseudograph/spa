#pragma once

#include "query_processing_system/query/design_entities/entity_type/IEntity.h"

class IVisitsProcedure;

class IProcedure : public virtual IEntity {
public:
    virtual void queryAbstractions(const std::shared_ptr<IVisitsProcedure>& v) = 0;
};
