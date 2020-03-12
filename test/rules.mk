MODULE_TYPE := app
MODULE_HEADER_DIRS := ../brdlib ../basemodules ../sidedrivers

MODULE_FLAGS := -Wno-unused-parameter -Wno-unused-variable -Wno-writable-strings

MODULE_LIBS := bambp bambpex mfm9009 brdlib

SRCS := brdlib_test
MODULE_SRCS += $(addprefix ,$(addsuffix .cpp,$(SRCS)))
