# makefile for sh proj in lnux

# variables for this makefile

C = gcc
OBJS = main.o strcnt.o cmdarr.o cmdexc.o
HDRS = yjsh_hf.h
OPFLAGS = -o
CCFLAGS = -c

# targets , their dependencies and their commands
output : $(OBJS)
	$(C) $(OPFLAGS) output $(OBJS)

cmdexc.o : cmdexc.c
	$(C) $(CCFLAGS) $<

cmdarr.o : cmdarr.c
	$(C) $(CCFLAGS) $<

strcnt.o : strcnt.c
	$(C) $(CCFLAGS) $<

main.o : main.c
	$(C) $(CCFLAGS) $<

$(OBJS) : $(HDRS)