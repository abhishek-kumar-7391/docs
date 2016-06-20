a:=$(var)
var=abc.c

ifeq (0,${MAKELEVEL})
whoami := $(shell whoami)
host-type := $(shell arch)
MAKE := ${MAKE} host-type=${host-type} whoami=${whoami}
endif

src := a.c b.c c.c .c
obj := $(src:%.c=%.o)
obj +=aa.c

ifeq ($(origin $(aa)),)
aa=asas
endif
aa ?= hello
aa ?= bye
file := $(lastword $(MAKEFILE_LIST))


file_list := $(shell find . -name "*.c")




ifeq ($(.DEFAULT_GOAL),)
	@echo "no default goal" 
all : abc
	$(warning using as default goal)
endif

abc : 
	@echo $(.DEFAULT_GOAL)
	@echo $(obj)
	@echo $(aa)
	@echo $(file_list)
	@echo $(file)
