DATE := `date +'%Y%m%d'`
VERSION := "v1.0"

CC        := gcc
LD        := gcc

TAR_FILENAME := PrimeSearcher-$(VERSION)-$(DATE).tar.gz

MODULES   := api apps lib
SRC_DIR   := $(addprefix src/,$(MODULES)) src
BUILD_DIR := $(addprefix build/,$(MODULES)) build

SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.c))
OBJ       := $(patsubst src/%.c,build/%.o,$(SRC))
INCLUDES  := include

vpath %.c $(SRC_DIR)

define make-goal
$1/%.o: %.c
	$(CC) -std=gnu99 -Wall -g -c $$< -o $$@
endef

.PHONY: all checkdirs clean



checkdirs: $(BUILD_DIR)
$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)

distclean:
	@rm -rf $(BUILD_DIR)
	@-rm -f *.tar.gz || true


$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))

dist:
	@tar --exclude=build --exclude=*.tar.gz --exclude=*.git -czvf mictcp-bundle.tar.gz ../mictcp
