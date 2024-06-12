#include "render_factory.hpp"

using namespace ruis::render::null;

utki::shared_ref<ruis::render::frame_buffer> render_factory::create_framebuffer(
	std::shared_ptr<ruis::render::texture_2d> color,
	std::shared_ptr<ruis::render::texture_depth> depth,
	std::shared_ptr<ruis::render::texture_stencil> stencil
)
{
	return utki::make_shared<frame_buffer>();
}
