#pragma once

#include <ruis/render/vertex_array.hpp>

#include "index_buffer.hpp"
#include "vertex_buffer.hpp"

namespace ruis::render::null {

class vertex_array : public ruis::render::vertex_array
{
public:
	vertex_array();
};

} // namespace ruis::render::null
