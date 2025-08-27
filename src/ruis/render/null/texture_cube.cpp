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

#include "texture_cube.hpp"

using namespace ruis::render::null;

texture_cube::texture_cube(
	utki::shared_ref<ruis::render::context> rendering_context, //
	rasterimage::image_variant&& positive_x,
	rasterimage::image_variant&& negative_x,
	rasterimage::image_variant&& positive_y,
	rasterimage::image_variant&& negative_y,
	rasterimage::image_variant&& positive_z,
	rasterimage::image_variant&& negative_z
) :
	ruis::render::texture_cube(std::move(rendering_context)),
	positive_x(std::move(positive_x)),
	negative_x(std::move(negative_x)),
	positive_y(std::move(positive_y)),
	negative_y(std::move(negative_y)),
	positive_z(std::move(positive_z)),
	negative_z(std::move(negative_z))
{}
