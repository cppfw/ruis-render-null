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

#include <variant>
#include <vector>

#include <r4/vector.hpp>
#include <ruis/render/vertex_buffer.hpp>
#include <utki/span.hpp>

namespace ruis::render::null {

class vertex_buffer : public ruis::render::vertex_buffer
{
public:
	const std::variant<
		std::vector<float>, //
		std::vector<r4::vector2<float>>,
		std::vector<r4::vector3<float>>,
		std::vector<r4::vector4<float>>>
		vertices;

	vertex_buffer(
		utki::shared_ref<ruis::render::context> rendering_context, //
		utki::span<const float> vertices
	);
	vertex_buffer(
		utki::shared_ref<ruis::render::context> rendering_context, //
		utki::span<const r4::vector2<float>> vertices
	);
	vertex_buffer(
		utki::shared_ref<ruis::render::context> rendering_context, //
		utki::span<const r4::vector3<float>> vertices
	);
	vertex_buffer(
		utki::shared_ref<ruis::render::context> rendering_context, //
		utki::span<const r4::vector4<float>> vertices
	);
};

} // namespace ruis::render::null