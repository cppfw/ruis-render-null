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

#include <ruis/render/vertex_array.hpp>

#include "index_buffer.hpp"
#include "vertex_buffer.hpp"

namespace ruis::render::null {

class vertex_array : public ruis::render::vertex_array
{
public:
	vertex_array(
		utki::shared_ref<const ruis::render::context> rendering_context, //
		std::vector<utki::shared_ref<const ruis::render::vertex_buffer>> buffers,
		utki::shared_ref<const ruis::render::index_buffer> indices,
		ruis::render::vertex_array::mode rendering_mode
	);
};

} // namespace ruis::render::null
