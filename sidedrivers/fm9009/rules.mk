MODULE_TYPE := static
MODULE_HEADER_DIRS := ../../brdlib

MODULE_FLAGS := -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

MODULE_LIBS := brdlib

SRCS := fm9009_adc_service fm9009_dac_service fm9009_ddc_service mfm9009
MODULE_SRCS := $(addprefix ,$(addsuffix .cpp,$(SRCS)))
