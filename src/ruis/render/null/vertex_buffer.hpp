#pragma once

#include <ruis/render/vertex_buffer.hpp>

namespace ruis::render::null {

class vertex_buffer : public ruis::render::vertex_buffer
{
public:
	vertex_buffer();
};

} // namespace ruis::render::null