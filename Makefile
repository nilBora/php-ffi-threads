
.PHONY: build
build: ## build library.o and library.so
		gcc -o ./ffiLib/library.o -c ./ffiLib/library.c
		gcc -shared -o ./ffiLib/library.so ./ffiLib/library.o  -lm

.PHONY: help
help: ## display this help message
	@cat $(MAKEFILE_LIST) | grep -e "^[a-zA-Z_\-]*: *.*## *" | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[32m%-30s\033[0m %s\n", $$1, $$2}'
