MODULE_TYPE := static
MODULE_HEADER_DIRS := modules services

MODULE_FLAGS := -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

MODULE_LIBS := brdlib

SRCS := module storage basemodule submodule module_control
MODULE_SRCS := $(addprefix modules/,$(addsuffix .cpp,$(SRCS)))

SRCS := service services_list stream_service adc_service dac_service ddc_service
MODULE_SRCS += $(addprefix services/,$(addsuffix .cpp,$(SRCS)))
