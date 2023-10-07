#pragma once

#include <cstdint>

namespace ezdb {
  using idx_t = uint64_t;
  using row_t = int64_t;
  using hash_t = uint64_t;
  //! Type used for transaction timestamps
  using transaction_t = idx_t;
}