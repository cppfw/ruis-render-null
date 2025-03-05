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

#include "vertex_buffer.hpp"

using namespace ruis::render::null;

vertex_buffer::vertex_buffer(
	utki::shared_ref<ruis::render::renderer> renderer, //
	utki::span<const float> vertices
) :
	ruis::render::vertex_buffer(
		std::move(renderer), //
		vertices.size()
	),
	vertices(utki::make_vector(vertices))
{}

vertex_buffer::vertex_buffer(
	utki::shared_ref<ruis::render::renderer> renderer, //
	utki::span<const r4::vector2<float>> vertices
) :
	ruis::render::vertex_buffer(
		std::move(renderer), //
		vertices.size()
	),
	vertices(utki::make_vector(vertices))
{}

vertex_buffer::vertex_buffer(
	utki::shared_ref<ruis::render::renderer> renderer, //
	utki::span<const r4::vector3<float>> vertices
) :
	ruis::render::vertex_buffer(
		std::move(renderer), //
		vertices.size()
	),
	vertices(utki::make_vector(vertices))
{}

vertex_buffer::vertex_buffer(
	utki::shared_ref<ruis::render::renderer> renderer, //
	utki::span<const r4::vector4<float>> vertices
) :
	ruis::render::vertex_buffer(
		std::move(renderer), //
		vertices.size()
	),
	vertices(utki::make_vector(vertices))
{}
