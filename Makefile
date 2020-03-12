
MAKEROOT = $(CURDIR)
BUILDDIR = .build
BUILDDIR := $(BUILDDIR)/$(if $(filter Windows_NT,$(OS)),windows,linux)
RELEASE = yes
USE_CLANG = no
USE_SUFFIX64 = no

export MAKEROOT
export BUILDDIR
export RELEASE
export USE_CLANG
export USE_SUFFIX64

all::
	$(MAKE) -f $(MAKEROOT)/make/engine.mk --no-print-directory -C brdlib
	$(MAKE) -f $(MAKEROOT)/make/engine.mk --no-print-directory -C basemodules/bambpex
	$(MAKE) -f $(MAKEROOT)/make/engine.mk --no-print-directory -C basemodules/bambp
	$(MAKE) -f $(MAKEROOT)/make/engine.mk --no-print-directory -C sidedrivers/mfm9009
	$(MAKE) -f $(MAKEROOT)/make/engine.mk --no-print-directory -C test

clean::
	$(MAKE) -f $(MAKEROOT)/make/engine.mk clean -C brdlib
	$(MAKE) -f $(MAKEROOT)/make/engine.mk clean -C basemodules/bambpex
	$(MAKE) -f $(MAKEROOT)/make/engine.mk clean -C basemodules/bambp
	$(MAKE) -f $(MAKEROOT)/make/engine.mk clean -C sidedrivers/mfm9009
	$(MAKE) -f $(MAKEROOT)/make/engine.mk clean -C test
