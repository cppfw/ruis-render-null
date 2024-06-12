#include "vertex_array.hpp"

using namespace ruis::render::null;

vertex_array::vertex_array() :
	ruis::render::vertex_array(
		{utki::make_shared<vertex_buffer>()},
		utki::make_shared<index_buffer>(),
		ruis::render::vertex_array::mode::triangles
	)
{}
