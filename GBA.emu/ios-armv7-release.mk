config_ios_jb := 1
O_RELEASE := 1
O_LTO := 1
-include config.mk
include $(IMAGINE_PATH)/make/iOS-armv7-gcc.mk
include build.mk
HIGH_OPTIMIZE_CFLAGS := -O3 $(HIGH_OPTIMIZE_CFLAGS_MISC)
