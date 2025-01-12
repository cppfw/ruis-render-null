include prorab.mk
include prorab-license.mk
include prorab-clang-format.mk
include prorab-install-dbgsrc.mk

$(eval $(call prorab-config, ../config))

this_name := ruis-render-null

this_soname := $(shell cat $(d)soname.txt)

this_srcs += $(call prorab-src-dir,.)

ifeq ($(os), linux)
    this_ldlibs +=
else ifeq ($(os), windows)
    this_ldlibs +=
else ifeq ($(os), macosx)
    this_ldlibs +=
endif

this_ldlibs += -lruis -lutki -lrasterimage

$(eval $(prorab-build-lib))

this_license_file := ../LICENSE
this_src_dir := ruis
$(eval $(prorab-license))

$(eval $(prorab-clang-format))

$(eval $(prorab-install-dbgsrc))
