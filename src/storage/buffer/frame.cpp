#include "storage/buffer/frame.hpp"

namespace ezdb {

FrameId::FrameId(int file_desc, PageNum page_num)
    : file_desc_(file_desc), page_num_(page_num) {
      
    }

} // namespace ezdb