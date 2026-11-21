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

#include <rasterimage/image_variant.hpp>
#include <ruis/render/factory.hpp>

namespace ruis::render::null {

class factory : public ruis::render::factory
{
public:
	factory() = default;

	utki::shared_ref<shaders> make_shaders() const override
	{
		return utki::make_shared<shaders>();
	}

	utki::shared_ref<index_buffer> make_index_buffer(utki::span<const uint16_t> indices) const override;
	utki::shared_ref<index_buffer> make_index_buffer(utki::span<const uint32_t> indices) const override;

	utki::shared_ref<texture_2d> make_texture_2d(
		rasterimage::format format,
		rasterimage::dimensioned::dimensions_type dims,
		texture_2d_parameters params
	) const override;

	utki::shared_ref<texture_2d> make_texture_2d(const rasterimage::image_variant& imvar, texture_2d_parameters params)
		const override;

	utki::shared_ref<texture_2d> make_texture_2d(rasterimage::image_variant&& imvar, texture_2d_parameters params)
		const override;

	utki::shared_ref<texture_depth> make_texture_depth(r4::vector2<uint32_t> dims) const override;

	utki::shared_ref<texture_cube> make_texture_cube(
		rasterimage::image_variant&& positive_x,
		rasterimage::image_variant&& negative_x,
		rasterimage::image_variant&& positive_y,
		rasterimage::image_variant&& negative_y,
		rasterimage::image_variant&& positive_z,
		rasterimage::image_variant&& negative_z
	) const override;

	utki::shared_ref<vertex_array> make_vertex_array(
		std::vector<utki::shared_ref<const vertex_buffer>> buffers,
		utki::shared_ref<const index_buffer> indices,
		vertex_array::mode rendering_mode
	) const override;

	utki::shared_ref<vertex_buffer> make_vertex_buffer( //
		utki::span<const float> vertices
	) const override;

	utki::shared_ref<vertex_buffer> make_vertex_buffer( //
		utki::span<const r4::vector2<float>> vertices
	) const override;

	utki::shared_ref<vertex_buffer> make_vertex_buffer( //
		utki::span<const r4::vector3<float>> vertices
	) const override;

	utki::shared_ref<vertex_buffer> make_vertex_buffer( //
		utki::span<const r4::vector4<float>> vertices
	) const override;
};

} // namespace ruis::render::null
