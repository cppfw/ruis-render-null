include prorab.mk
include prorab-license.mk
include prorab-clang-format.mk
include prorab-install-dbgsrc.mk

$(eval $(call prorab-config, ../config))

this_src_dir := ruis

this_name := ruis-render-null$(this_dbg)

this_soname := $(shell cat $(d)soname.txt)

this_srcs += $(call prorab-src-dir, $(this_src_dir))

# TODO: add linking to dbg versions of all libs
this_ldlibs += -lruis$(this_dbg)
this_ldlibs += -lutki$(this_dbg)
this_ldlibs += -lrasterimage

$(eval $(prorab-build-lib))

this_license_file := ../LICENSE
$(eval $(prorab-license))

$(eval $(prorab-clang-format))

$(eval $(prorab-install-dbgsrc))
