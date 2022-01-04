MKLROOT 	 ?= /opt/intel/oneapi/mkl/latest

MKL_CFLAGS 		:= 	-I$(MKLROOT)/include

CXX_FLAGS = -O0 -g3 $(MKL_CFLAGS)

MKL_LIBS 	 	:= 	 -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_intel_thread.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -liomp5 -lpthread -lm -ldl
			
LD_LIBS = $(MKL_LIBS)

CXX = dpcpp

OUTPUT = output.txt

SRC = ../src

EXECUTABLE = vtune_test

$(EXECUTABLE): main.o
	$(CXX) main.o -o $(EXECUTABLE) $(LD_LIBS)

main.o: $(SRC)/main.cpp
	$(CXX) -c $(CXX_FLAGS) $(SRC)/main.cpp

.PHONY: clean run run_out

clean:
	rm *.o $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

run_out: $(EXECUTABLE)
	./$(EXECUTABLE) > $(OUTPUT)