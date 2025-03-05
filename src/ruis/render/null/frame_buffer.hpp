/*
ruis-render-null - null renderer

Copyright (C) 2024-2024  Ivan Gagis <igagis@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/* ================ LICENSE END ================ */

#pragma once

#include <ruis/render/frame_buffer.hpp>

namespace ruis::render::null {

class frame_buffer : public ruis::render::frame_buffer
{
public:
	const std::shared_ptr<ruis::render::texture_2d> color;
	const std::shared_ptr<ruis::render::texture_depth> depth;
	const std::shared_ptr<ruis::render::texture_stencil> stencil;

	frame_buffer(
		utki::shared_ref<ruis::render::renderer> renderer,
		std::shared_ptr<ruis::render::texture_2d> color,
		std::shared_ptr<ruis::render::texture_depth> depth,
		std::shared_ptr<ruis::render::texture_stencil> stencil
	);
};

} // namespace ruis::render::null