all: generator detector
.PHONY: all clean 

OBJS_DETECTOR = common.o hldetector.o # OBJS 
OBJS_GENERATOR = common.o hlgenerator.o # OBJS_2
EXECUTABLES = generator detector 

generator: $(OBJS_GENERATOR)
	cc -o $@ $(OBJS_GENERATOR)

detector: $(OBJS_DETECTOR)
	cc -o $@ $(OBJS_DETECTOR)

.c.o:
	cc -c -o $@ $<

clean:
	@rm -f -- $(OBJS_DETECTOR) $(OBJS_GENERATOR) $(EXECUTABLES)
