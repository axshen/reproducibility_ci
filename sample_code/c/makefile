CPP = /usr/local/opt/llvm/bin/clang
CPPFLAGS = -I/usr/local/opt/llvm/include -fopenmp
LDFLAGS = -L/usr/local/opt/llvm/lib

pi: pi.c
	$(CPP) $(CPPFLAGS) $^ -o $@ $(LDFLAGS)
