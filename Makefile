CXX = clang++ -g -Xclang -load -Xclang /home/work/llvm-3.5.0.src/Release+Asserts/lib/AccessInstrument.so
CXXFLAGS = -std=c++0x
LDFLAGS = -pthread -lm -L /home/work/llvm-3.5.0.src/projects/llvm-access-instrumentation/AccessInstrument/library -linstrumentation
SRC = actonization-test-1-aligned.cpp
EXE = actonization-test-1-aligned
all:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SRC) -o $(EXE)

clean:
	rm -f actonization-test-1-aligned map_*
