CC=gcc -fopenmp
CFLAGS=-I.
.PHONY: all_targets
all_targets: make_dir make_critical make_for make_parallel make_reduction make_section make_do_while

.PHONY: make_dir
make_dir:
	test -d "build" || mkdir build
	
.PHONY: make_parallel
make_parallel: exemplo_parallel.c
	$(CC) exemplo_parallel.c -o build/exemplo_parallel $(CFLAGS)

.PHONY: make_for
make_for: exemplo_for.c
	$(CC) exemplo_for.c -o build/exemplo_for $(CFLAGS)

.PHONY: make_critical
make_critical: exemplo_critical.c
	$(CC) exemplo_critical.c -o build/exemplo_critical $(CFLAGS)

.PHONY: make_section
make_section: exemplo_section.c
	$(CC) exemplo_section.c -o build/exemplo_section $(CFLAGS)

.PHONY: make_reduction
make_reduction: exemplo_reduction.c
	$(CC) exemplo_reduction.c -o build/exemplo_reduction $(CFLAGS)

.PHONY: make_do_while
make_do_while: exemplo_do_while.c
	$(CC) exemplo_do_while.c -o build/exemplo_do_while $(CFLAGS)