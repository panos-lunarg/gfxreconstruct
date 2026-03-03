#!/bin/bash

set -x

cd /data/app

APP_NAME="de.saschawillems.vulkanTriangle"

APP_ARM64=`find . | grep $APP_NAME | grep "/lib/arm64$"`
GFXR_ARM64=`find . | grep "lunarg\.gfxreconstruct\.replay" | grep "/lib/arm64$"`

# chmod 777 $GFXR_ARM64/libVkLayer_gfxreconstruct.so
# chcon u:object_r:system_lib_file:s0 $GFXR_ARM64/libVkLayer_gfxreconstruct.so

cp $GFXR_ARM64/libVkLayer_gfxreconstruct.so $APP_ARM64/libVkLayer_gfxreconstruct.so; chmod 777 $APP_ARM64/libVkLayer_gfxreconstruct.so
# chcon u:object_r:system_lib_file:s0 $APP_ARM64/libVkLayer_gfxreconstruct.so

# cp $GFXR_ARM64/libVkLayer_gfxreconstruct.so /data/local/tmp/libVkLayer_gfxreconstruct.so; chmod 777 /data/local/tmp/libVkLayer_gfxreconstruct.so
# chcon u:object_r:system_lib_file:s0 /data/local/tmp/libVkLayer_gfxreconstruct.so

mkdir -p /data/local/debug/vulkan/
cp $GFXR_ARM64/libVkLayer_gfxreconstruct.so /data/local/debug/vulkan/libVkLayer_gfxreconstruct.so; chmod 777 /data/local/debug/vulkan/libVkLayer_gfxreconstruct.so

# cp $GFXR_ARM64/libsigaction_wrapper.so $APP_ARM64/libsigaction_wrapper.so; chmod 777 $APP_ARM64/libsigaction_wrapper.so
# chcon u:object_r:system_lib_file:s0 $APP_ARM64/libsigaction_wrapper.so
# setprop wrap.$APP_NAME LD_PRELOAD=$APP_ARM64/libsigaction_wrapper.so

cp $GFXR_ARM64/libsigaction_wrapper.so /data/local/tmp/libsigaction_wrapper.so; chmod 777 /data/local/tmp/libsigaction_wrapper.so
chcon u:object_r:system_lib_file:s0 /data/local/tmp/libsigaction_wrapper.so
setprop wrap.$APP_NAME LD_PRELOAD=/data/local/tmp/libsigaction_wrapper.so


# setprop wrap.$APP_NAME ''

set +x
