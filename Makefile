TARGETS := libvc4clist.so libvc4clist.a
SRCS := vc4clist.c
OBJS := $(SRCS:%.c=%.c.o)
DEPS := $(SRCS:%.c=%.c.d)
ALLDEPS = $(MAKEFILE_LIST_SANS_DEPS)
CFLAGS_LOCAL := -Wall -Wextra -O2 -g
ARFLAGS := cr

CC := gcc
AR := ar
RANLIB := ranlib
RM := rm -f

all:

VALID_MAKECMDGOALS := all $(TARGETS) %.c.d %.c.o clean
NONEED_DEP_MAKECMDGOALS := clean

EXTRA_MAKECMDGOALS := $(filter-out $(VALID_MAKECMDGOALS), $(MAKECMDGOALS))
ifneq '$(EXTRA_MAKECMDGOALS)' ''
  $(error No rule to make target `$(word 1, $(EXTRA_MAKECMDGOALS))')
else
  ifeq '$(filter-out $(NONEED_DEP_MAKECMDGOALS), $(MAKECMDGOALS))' '$(MAKECMDGOALS)'
    sinclude $(DEPS)
	else
    ifneq '$(words $(MAKECMDGOALS))' '1'
      $(error Specify only one target if you want to make target which needs no source code dependency)
    endif
  endif
endif

MAKEFILE_LIST_SANS_DEPS := $(filter-out %.c.d, $(MAKEFILE_LIST))

COMPILE.o = $(CC) $(CFLAGS) $(EXTRACFLAGS) $(CFLAGS_LOCAL) $(CPPFLAGS) $(EXTRACPPFLAGS) $(TARGET_ARCH) -shared
COMPILE.c = $(CC) $(CFLAGS) $(EXTRACFLAGS) $(CFLAGS_LOCAL) $(CPPFLAGS) $(EXTRACPPFLAGS) $(TARGET_ARCH) -c
COMPILE.d = $(CC) $(CFLAGS) $(EXTRACFLAGS) $(CFLAGS_LOCAL) $(CPPFLAGS) $(EXTRACPPFLAGS) $(TARGET_ARCH) -M -MP -MT $<.o -MF $@

all: $(TARGETS)

%.a: $(OBJS) $(ALLDEPS)
	$(AR) $(ARFLAGS) $@ $(OBJS)
	$(RANLIB) $@

%.so: $(OBJS) $(ALLDEPS)
	$(COMPILE.o) $(OUTPUT_OPTION) $(OBJS) $(LOADLIBES) $(LDLIBS) $(LDLIBS_LOCAL)

%.c.o: %.c $(ALLDEPS)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

%.c.d: %.c $(ALLDEPS)
	$(COMPILE.d) $<

.PHONY: clean
clean:
	$(RM) $(TARGETS)
	$(RM) $(OBJS)
	$(RM) $(DEPS)
