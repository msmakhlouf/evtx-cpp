#include <cstdio>
#include "Evtx.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		puts("Usage: evtxdump c:\\path\\to\\file.evtx");
		return 0;
	}
	Evtx::File file(argv[1]);
	int i = 0;
	return 0;
}
