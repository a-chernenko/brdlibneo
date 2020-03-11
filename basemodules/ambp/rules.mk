MODULE_TYPE := static
MODULE_HEADER_DIRS := ../../brdlib

MODULE_FLAGS := -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

MODULE_LIBS := brdlib

SRCS := ambp
MODULE_SRCS := $(addprefix ,$(addsuffix .cpp,$(SRCS)))
