#include <ruis/render/null/renderer.hpp>

int main(int argc, const char** argv){
	auto r = utki::make_shared<ruis::render::null::renderer>();

	std::cout << "hello ruis-render-null! viewport = " << r.get().get_viewport() << std::endl;

	return 0;
}