# 需要排除的目录
exclude_dirs := include bin
# 取得当前子目录深度为1的所有目录名称

DIRS := $(shell find . -maxdepth 1 -type d)
DIRS := $(basename $(patsubst ./%,%,$(DIRS)))
DIRS := $(filter-out $(exclude_dirs),$(DIRS))

.PHONY: release clean

release: 
	@for x in $(DIRS); \
	do \
		make -C $$x; \
	done

clean:
	@for x in $(DIRS); \
	do \
		make -C $$x $@; \
	done
