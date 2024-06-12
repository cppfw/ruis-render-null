#pragma once

#include <ruis/render/frame_buffer.hpp>

namespace ruis::render::null {

class frame_buffer : public ruis::render::frame_buffer
{
public:
	frame_buffer();
};

} // namespace ruis::render::null