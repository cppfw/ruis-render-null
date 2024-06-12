#pragma once

#include <ruis/render/index_buffer.hpp>

namespace ruis::render::null {

class index_buffer : public ruis::render::index_buffer
{
public:
	index_buffer();
};

} // namespace ruis::render::null