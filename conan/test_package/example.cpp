#include <ruis/render/null/context.hpp>

int main(int argc, const char** argv){
	auto c = utki::make_shared<ruis::render::null::context>();

	std::cout << "hello ruis-render-null! viewport = " << c.get().get_viewport() << std::endl;

	return 0;
}