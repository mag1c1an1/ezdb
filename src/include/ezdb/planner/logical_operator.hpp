#pragma once

#include "ezdb/common/enums/logical_operator_type.hpp"

namespace ezdb {
class LogicalOperator {
 public:
  explicit LogicalOperator(LogicalOperatorType type);
  LogicalOperatorType type;

 protected:
  virtual void ResolveTypes() = 0;

 public:
  template <class TARGET>
  TARGET& Cast() {
    if (TARGET::TYPE != LogicalOperatorType::LOGICAL_INVALID &&
        type != TARGET::TYPE) {}
  }
};
}  // namespace ezdb