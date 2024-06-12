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

#include <memory>

#include <ruis/render/renderer.hpp>

namespace ruis::render::null {

class null_texture_2d : public ruis::render::texture_2d
{
public:
	null_texture_2d() :
		ruis::render::texture_2d(r4::vector2<uint32_t>(1, 2))
	{}
};

class null_texture_depth : public ruis::render::texture_depth
{
public:
	null_texture_depth() :
		ruis::render::texture_depth(r4::vector2<uint32_t>(1, 2))
	{}
};

class null_texture_cube : public ruis::render::texture_cube
{
public:
	null_texture_cube() :
		ruis::render::texture_cube()
	{}
};

class null_frame_buffer : public ruis::render::frame_buffer
{
public:
	null_frame_buffer() :
		ruis::render::frame_buffer(nullptr, nullptr, nullptr)
	{}
};

class null_index_buffer : public ruis::render::index_buffer
{
public:
};

class null_vertex_buffer : public ruis::render::vertex_buffer
{
public:
	null_vertex_buffer() :
		ruis::render::vertex_buffer(1)
	{}
};

class null_vertex_array : public ruis::render::vertex_array
{
public:
	null_vertex_array();
};

class null_factory : public ruis::render::render_factory
{
public:
	utki::shared_ref<ruis::render::frame_buffer> create_framebuffer(
		std::shared_ptr<ruis::render::texture_2d> color,
		std::shared_ptr<ruis::render::texture_depth> depth,
		std::shared_ptr<ruis::render::texture_stencil> stencil
	) override
	{
		return utki::make_shared<null_frame_buffer>();
	}

	utki::shared_ref<ruis::render::index_buffer> create_index_buffer(utki::span<const uint16_t> indices) override
	{
		return utki::make_shared<null_index_buffer>();
	}

	utki::shared_ref<ruis::render::index_buffer> create_index_buffer(utki::span<const uint32_t> indices) override
	{
		return utki::make_shared<null_index_buffer>();
	}

	std::unique_ptr<ruis::render::render_factory::shaders> create_shaders() override
	{
		return nullptr;
	}

	utki::shared_ref<ruis::render::texture_2d> create_texture_2d(
		rasterimage::format format,
		rasterimage::dimensioned::dimensions_type dims,
		texture_2d_parameters params
	) override
	{
		return utki::make_shared<null_texture_2d>();
	}

	utki::shared_ref<ruis::render::texture_2d> create_texture_2d(
		const rasterimage::image_variant& imvar,
		texture_2d_parameters params
	) override
	{
		return utki::make_shared<null_texture_2d>();
	}

	utki::shared_ref<ruis::render::texture_2d> create_texture_2d(
		rasterimage::image_variant&& imvar, // NOLINT(cppcoreguidelines-rvalue-reference-param-not-moved)
		texture_2d_parameters params
	) override
	{
		return utki::make_shared<null_texture_2d>();
	}

	utki::shared_ref<ruis::render::texture_depth> create_texture_depth(r4::vector2<uint32_t> dims) override
	{
		return utki::make_shared<null_texture_depth>();
	}

	utki::shared_ref<ruis::render::texture_cube> create_texture_cube(
		rasterimage::image_variant&& positive_x, // NOLINT(cppcoreguidelines-rvalue-reference-param-not-moved)
		rasterimage::image_variant&& negative_x, // NOLINT(cppcoreguidelines-rvalue-reference-param-not-moved)
		rasterimage::image_variant&& positive_y, // NOLINT(cppcoreguidelines-rvalue-reference-param-not-moved)
		rasterimage::image_variant&& negative_y, // NOLINT(cppcoreguidelines-rvalue-reference-param-not-moved)
		rasterimage::image_variant&& positive_z, // NOLINT(cppcoreguidelines-rvalue-reference-param-not-moved)
		rasterimage::image_variant&& negative_z // NOLINT(cppcoreguidelines-rvalue-reference-param-not-moved)
	) override
	{
		return utki::make_shared<null_texture_cube>();
	}

	utki::shared_ref<ruis::render::vertex_array> create_vertex_array(
		std::vector<utki::shared_ref<const ruis::render::vertex_buffer>> buffers,
		const utki::shared_ref<const ruis::render::index_buffer>& indices,
		ruis::render::vertex_array::mode rendering_mode
	) override
	{
		return utki::make_shared<null_vertex_array>();
	}

	utki::shared_ref<ruis::render::vertex_buffer> create_vertex_buffer(utki::span<const float> vertices) override
	{
		return utki::make_shared<null_vertex_buffer>();
	}

	utki::shared_ref<ruis::render::vertex_buffer> create_vertex_buffer(utki::span<const r4::vector2<float>> vertices
	) override
	{
		return utki::make_shared<null_vertex_buffer>();
	}

	utki::shared_ref<ruis::render::vertex_buffer> create_vertex_buffer(utki::span<const r4::vector3<float>> vertices
	) override
	{
		return utki::make_shared<null_vertex_buffer>();
	}

	utki::shared_ref<ruis::render::vertex_buffer> create_vertex_buffer(utki::span<const r4::vector4<float>> vertices
	) override
	{
		return utki::make_shared<null_vertex_buffer>();
	}
};

class null_renderer : public ruis::render::renderer
{
public:
	null_renderer() :
		ruis::render::renderer(std::make_unique<null_factory>(), params())
	{}

	void clear_framebuffer_color() override {}

	void clear_framebuffer_depth() override {}

	void clear_framebuffer_stencil() override {}

	r4::vector2<uint32_t> to_window_coords(ruis::vec2 point) const override
	{
		return {0, 0};
	}

	r4::rectangle<uint32_t> get_scissor() const override
	{
		return {0, 0};
	}

	r4::rectangle<uint32_t> get_viewport() const override
	{
		return {0, 0};
	}

	bool is_scissor_enabled() const noexcept override
	{
		return false;
	}

	void enable_blend(bool enable) override {}

	void set_blend_func(blend_factor src_color, blend_factor dst_color, blend_factor src_alpha, blend_factor dst_alpha)
		override
	{}

	void set_framebuffer_internal(ruis::render::frame_buffer* fb) override {}

	void enable_scissor(bool enable) override {}

	void set_scissor(r4::rectangle<uint32_t> r) override {}

	void set_viewport(r4::rectangle<uint32_t> r) override {}

	bool is_depth_enabled() const noexcept override
	{
		return false;
	}

	void enable_depth(bool enable) override {}
};

} // namespace ruis::render::null