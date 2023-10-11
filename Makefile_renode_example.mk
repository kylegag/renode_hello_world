PROJECT = renode-example
BUILD_DIR = bin

CFILES = renode-example.c

DEVICE=nrf52840
OOCD_FILE = board/nordic_nrf52_dk.cfg

OPENCM3_DIR=libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
