
.PHONY: all
all: build run

.PHONY: build
build:
	cmake -B build

.PHONY: run
run: build
	@cd build && make run --no-print-directory

.PHONY: fclean
fclean:
	@rm -rf build
	@echo "All build files and the executable have been removed."

.PHONY: re
re: fclean build run