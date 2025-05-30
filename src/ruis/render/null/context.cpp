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

#include "context.hpp"

#include "frame_buffer.hpp"
#include "index_buffer.hpp"
#include "texture_2d.hpp"
#include "texture_cube.hpp"
#include "texture_depth.hpp"
#include "vertex_array.hpp"
#include "vertex_buffer.hpp"

using namespace ruis::render::null;

utki::shared_ref<ruis::render::frame_buffer> context::make_framebuffer(
	std::shared_ptr<ruis::render::texture_2d> color,
	std::shared_ptr<ruis::render::texture_depth> depth,
	std::shared_ptr<ruis::render::texture_stencil> stencil
)
{
	return utki::make_shared<frame_buffer>(
		this->get_shared_ref(), //
		std::move(color),
		std::move(depth),
		std::move(stencil)
	);
}

utki::shared_ref<ruis::render::index_buffer> context::make_index_buffer(utki::span<const uint16_t> indices)
{
	return utki::make_shared<index_buffer>(
		this->get_shared_ref(), //
		indices
	);
}

utki::shared_ref<ruis::render::index_buffer> context::make_index_buffer(utki::span<const uint32_t> indices)
{
	return utki::make_shared<index_buffer>(
		this->get_shared_ref(), //
		indices
	);
}

utki::shared_ref<ruis::render::texture_2d> context::make_texture_2d(
	rasterimage::format format,
	rasterimage::dimensioned::dimensions_type dims,
	texture_2d_parameters params
)
{
	return utki::make_shared<texture_2d>(
		this->get_shared_ref(), //
		rasterimage::image_variant(dims, format),
		std::move(params)
	);
}

utki::shared_ref<ruis::render::texture_2d> context::make_texture_2d(
	const rasterimage::image_variant& imvar,
	texture_2d_parameters params
)
{
	return utki::make_shared<texture_2d>(
		this->get_shared_ref(), //
		imvar,
		std::move(params)
	);
}

utki::shared_ref<ruis::render::texture_2d> context::make_texture_2d(
	rasterimage::image_variant&& imvar,
	texture_2d_parameters params
)
{
	return utki::make_shared<texture_2d>(
		this->get_shared_ref(), //
		std::move(imvar),
		std::move(params)
	);
}

utki::shared_ref<ruis::render::texture_depth> context::make_texture_depth(r4::vector2<uint32_t> dims)
{
	return utki::make_shared<texture_depth>(
		this->get_shared_ref(), //
		dims
	);
}

utki::shared_ref<ruis::render::texture_cube> context::make_texture_cube(
	rasterimage::image_variant&& positive_x,
	rasterimage::image_variant&& negative_x,
	rasterimage::image_variant&& positive_y,
	rasterimage::image_variant&& negative_y,
	rasterimage::image_variant&& positive_z,
	rasterimage::image_variant&& negative_z
)
{
	return utki::make_shared<texture_cube>(
		this->get_shared_ref(), //
		std::move(positive_x),
		std::move(negative_x),
		std::move(positive_y),
		std::move(negative_y),
		std::move(positive_z),
		std::move(negative_z)
	);
}

utki::shared_ref<ruis::render::vertex_array> context::make_vertex_array(
	std::vector<utki::shared_ref<const ruis::render::vertex_buffer>> buffers,
	utki::shared_ref<const ruis::render::index_buffer> indices,
	ruis::render::vertex_array::mode rendering_mode
)
{
	return utki::make_shared<vertex_array>(
		this->get_shared_ref(), //
		std::move(buffers),
		std::move(indices),
		rendering_mode
	);
}

utki::shared_ref<ruis::render::vertex_buffer> context::make_vertex_buffer(utki::span<const float> vertices)
{
	return utki::make_shared<vertex_buffer>(
		this->get_shared_ref(), //
		vertices
	);
}

utki::shared_ref<ruis::render::vertex_buffer> context::make_vertex_buffer(utki::span<const r4::vector2<float>> vertices)
{
	return utki::make_shared<vertex_buffer>(
		this->get_shared_ref(), //
		vertices
	);
}

utki::shared_ref<ruis::render::vertex_buffer> context::make_vertex_buffer(utki::span<const r4::vector3<float>> vertices)
{
	return utki::make_shared<vertex_buffer>(
		this->get_shared_ref(), //
		vertices
	);
}

utki::shared_ref<ruis::render::vertex_buffer> context::make_vertex_buffer(utki::span<const r4::vector4<float>> vertices)
{
	return utki::make_shared<vertex_buffer>(
		this->get_shared_ref(), //
		vertices
	);
}
