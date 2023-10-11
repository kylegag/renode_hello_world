OPENCM3_DIR=libopencm3
OPENCM3_COMMIT=master
OPENCM3_SETUP_FILE=$(OPENCM3_DIR)/$(OPENCM3_COMMIT)

all: $(OPENCM3_SETUP_FILE)
	@echo "Building renode example app"
	$(MAKE) -f Makefile_renode_example.mk

clean:
	$(MAKE) -f Makefile_renode_example.mk clean

# libopencm3 should really be included as a submodule in a real project
# Let's do a cheap hack and clone it here instead
$(OPENCM3_SETUP_FILE): $(OPENCM3_DIR)
	@echo "Initializing OPENCM3 Lib"
	git -C $(OPENCM3_DIR) checkout master
	$(MAKE) -C $(OPENCM3_DIR)
	touch $(OPENCM3_SETUP_FILE)

$(OPENCM3_DIR):
	git clone https://github.com/libopencm3/libopencm3.git $(OPENCM3_DIR)
