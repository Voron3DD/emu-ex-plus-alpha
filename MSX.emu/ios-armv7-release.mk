config_ios_jb := 1
O_RELEASE := 1
# crashes on some file IO operations with LTO, cause unknown
#O_LTO := 1
-include config.mk
include $(IMAGINE_PATH)/make/iOS-armv7-gcc.mk
include build.mk
