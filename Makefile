DATE 	  := `date +'%Y.%m.%d'`
VERSION   := v1.0

CC        := gcc
LD        := gcc

NAME 	  := PrimeSearcher_$(VERSION)
TAR_FILENAME := $(NAME)_$(DATE).tar.gz

LIBRARIES := lib
SRC_DIR   := $(addprefix src/,$(LIBRARIES)) src
BUILD_DIR := ./build
BUILD_DEST := $(BUILD_DIR)/$(NAME)

SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.c))

#.PHONY: all checkdirs clean

checkdirs: $(BUILD_DIR)
$(BUILD_DIR):
	@mkdir -p $@

all:
	@echo "make all :"
	@echo $(SRC)
	$(CC) -std=gnu99 -Wall -g $(SRC) -o $(BUILD_DEST) -lm -lpthread

clean:
	@rm -rf $(BUILD_DIR)
	@-rm -f *.primes || true

distclean:
	@rm -rf $(BUILD_DIR)
	@-rm -f *.tar.gz || true
	@-rm -f *.primes || true

dist:
	@tar --exclude=build --exclude=*.tar.gz --exclude=*.git --exclude=*.primes -czvf $(TAR_FILENAME) ./
