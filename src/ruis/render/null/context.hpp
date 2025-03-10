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

#include <ruis/render/context.hpp>

namespace ruis::render::null {

class context : public ruis::render::context
{
public:
	utki::shared_ref<ruis::render::context::shaders> create_shaders() override
	{
		return utki::make_shared<ruis::render::context::shaders>();
	}

	utki::shared_ref<ruis::render::frame_buffer> create_framebuffer(
		std::shared_ptr<ruis::render::texture_2d> color,
		std::shared_ptr<ruis::render::texture_depth> depth,
		std::shared_ptr<ruis::render::texture_stencil> stencil
	) override;

	utki::shared_ref<ruis::render::index_buffer> create_index_buffer(utki::span<const uint16_t> indices) override;
	utki::shared_ref<ruis::render::index_buffer> create_index_buffer(utki::span<const uint32_t> indices) override;

	utki::shared_ref<ruis::render::texture_2d> create_texture_2d(
		rasterimage::format format,
		rasterimage::dimensioned::dimensions_type dims,
		texture_2d_parameters params
	) override;

	utki::shared_ref<ruis::render::texture_2d> create_texture_2d(
		const rasterimage::image_variant& imvar,
		texture_2d_parameters params
	) override;

	utki::shared_ref<ruis::render::texture_2d> create_texture_2d(
		rasterimage::image_variant&& imvar,
		texture_2d_parameters params
	) override;

	utki::shared_ref<ruis::render::texture_depth> create_texture_depth(r4::vector2<uint32_t> dims) override;

	utki::shared_ref<ruis::render::texture_cube> create_texture_cube(
		rasterimage::image_variant&& positive_x,
		rasterimage::image_variant&& negative_x,
		rasterimage::image_variant&& positive_y,
		rasterimage::image_variant&& negative_y,
		rasterimage::image_variant&& positive_z,
		rasterimage::image_variant&& negative_z
	) override;

	utki::shared_ref<ruis::render::vertex_array> create_vertex_array(
		std::vector<utki::shared_ref<const ruis::render::vertex_buffer>> buffers,
		utki::shared_ref<const ruis::render::index_buffer> indices,
		ruis::render::vertex_array::mode rendering_mode
	) override;

	utki::shared_ref<ruis::render::vertex_buffer> create_vertex_buffer(utki::span<const float> vertices) override;

	utki::shared_ref<ruis::render::vertex_buffer> create_vertex_buffer(
		utki::span<const r4::vector2<float>> vertices
	) override;

	utki::shared_ref<ruis::render::vertex_buffer> create_vertex_buffer(
		utki::span<const r4::vector3<float>> vertices
	) override;

	utki::shared_ref<ruis::render::vertex_buffer> create_vertex_buffer(
		utki::span<const r4::vector4<float>> vertices
	) override;
};

} // namespace ruis::render::null