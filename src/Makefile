DIRS=factory factory_method abstract_factory singleton
DEST=install clean

all:%:
	@for x in $(DIRS); \
	do \
		make -C $$x $@; \
		if [ $$? != 0 ]; then \
			exit 1; \
		fi \
	done

$(DEST):%:
	@for x in $(DIRS); \
	do \
		make -C $$x $@; \
	done
