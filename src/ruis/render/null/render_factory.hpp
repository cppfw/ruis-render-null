#pragma once

#include <ruis/render/render_factory.hpp>

#include "frame_buffer.hpp"
#include "texture_2d.hpp"
#include "texture_cube.hpp"
#include "texture_depth.hpp"
#include "vertex_array.hpp"

namespace ruis::render::null {

class render_factory : public ruis::render::render_factory
{
public:
	utki::shared_ref<ruis::render::frame_buffer> create_framebuffer(
		std::shared_ptr<ruis::render::texture_2d> color,
		std::shared_ptr<ruis::render::texture_depth> depth,
		std::shared_ptr<ruis::render::texture_stencil> stencil
	) override;

	utki::shared_ref<ruis::render::index_buffer> create_index_buffer(utki::span<const uint16_t> indices) override
	{
		return utki::make_shared<index_buffer>();
	}

	utki::shared_ref<ruis::render::index_buffer> create_index_buffer(utki::span<const uint32_t> indices) override
	{
		return utki::make_shared<index_buffer>();
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
		return utki::make_shared<texture_2d>();
	}

	utki::shared_ref<ruis::render::texture_2d> create_texture_2d(
		const rasterimage::image_variant& imvar,
		texture_2d_parameters params
	) override
	{
		return utki::make_shared<texture_2d>();
	}

	utki::shared_ref<ruis::render::texture_2d> create_texture_2d(
		rasterimage::image_variant&& imvar, // NOLINT(cppcoreguidelines-rvalue-reference-param-not-moved)
		texture_2d_parameters params
	) override
	{
		return utki::make_shared<texture_2d>();
	}

	utki::shared_ref<ruis::render::texture_depth> create_texture_depth(r4::vector2<uint32_t> dims) override
	{
		return utki::make_shared<texture_depth>();
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
		return utki::make_shared<texture_cube>();
	}

	utki::shared_ref<ruis::render::vertex_array> create_vertex_array(
		std::vector<utki::shared_ref<const ruis::render::vertex_buffer>> buffers,
		const utki::shared_ref<const ruis::render::index_buffer>& indices,
		ruis::render::vertex_array::mode rendering_mode
	) override
	{
		return utki::make_shared<vertex_array>();
	}

	utki::shared_ref<ruis::render::vertex_buffer> create_vertex_buffer(utki::span<const float> vertices) override
	{
		return utki::make_shared<vertex_buffer>();
	}

	utki::shared_ref<ruis::render::vertex_buffer> create_vertex_buffer(utki::span<const r4::vector2<float>> vertices
	) override
	{
		return utki::make_shared<vertex_buffer>();
	}

	utki::shared_ref<ruis::render::vertex_buffer> create_vertex_buffer(utki::span<const r4::vector3<float>> vertices
	) override
	{
		return utki::make_shared<vertex_buffer>();
	}

	utki::shared_ref<ruis::render::vertex_buffer> create_vertex_buffer(utki::span<const r4::vector4<float>> vertices
	) override
	{
		return utki::make_shared<vertex_buffer>();
	}
};

} // namespace ruis::render::null
