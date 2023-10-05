#pragma once

#include <string>


#include "usual/types.hpp"

namespace ezdb {

class FrameId {
public:
FrameId(int file_desc,PageNum page_num);
bool equal_to(const FrameId &other) const;
bool operator==(const FrameId &other) const;
size_t hash() const;
PageNum page_num() const;

friend std::string to_string(const FrameId &frame_id);
private:
  int file_desc_;
  PageNum page_num_;
};

} // namespace ezdb