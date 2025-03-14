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
#include <ruis/render/context.hpp>
#include <ruis/render/texture_2d.hpp>

namespace ruis::render::null {

class texture_2d : public ruis::render::texture_2d
{
public:
	const ruis::render::context::texture_2d_parameters params;
	const rasterimage::image_variant image;

	texture_2d(
		utki::shared_ref<ruis::render::context> render_context, //
		rasterimage::image_variant image,
		ruis::render::context::texture_2d_parameters params
	);
};

} // namespace ruis::render::null
