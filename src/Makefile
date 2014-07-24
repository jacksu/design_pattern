
function get_dir() \
{ \
	ALL_DIR="" \
	for DIR in `ls -a $1` \
	do \
		if [ x"$(DIR)" != x"." -a -x"$(DIR)" != -x".." ] \
		then \
			if [ -d "$1/$(DIR)" ] \
			then \
				ALL_DIR += $(DIR) \
			fi \
		fi \
	done \
	echo $(ALL_DIR); \
}

#DIRS=factory factory_method abstract_factory singleton builder prototype
DIRS=`get_dir ./`
DEST=install clean

all:%:
	for x in $(DIRS); \
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
