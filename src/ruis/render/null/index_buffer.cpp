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

#include "index_buffer.hpp"

using namespace ruis::render::null;

index_buffer::index_buffer(
	utki::shared_ref<ruis::render::context> render_context, //
	utki::span<const uint16_t> indices
) :
	ruis::render::index_buffer(std::move(render_context)),
	indices(utki::make_vector(indices))
{}

index_buffer::index_buffer(
	utki::shared_ref<ruis::render::context> render_context, //
	utki::span<const uint32_t> indices
) :
	ruis::render::index_buffer(std::move(render_context)),
	indices(utki::make_vector(indices))
{}
