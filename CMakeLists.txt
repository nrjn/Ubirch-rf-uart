cmake_minimum_required(VERSION 3.5)
#set(CMAKE_TOOLCHAIN_FILE ../ubirch-meta/ubirch-arm-toolchain/cmake/ubirch-arm-gcc-toolchain.cmake)

project(ubirch-template C)

if (NOT BOARD)
  set(BOARD "ubirch1r02")
endif ()
require(PACKAGE ubirch BOARD ${BOARD} VERSION 1.0)

# add our executable
add_executable(ubirch-template main.c)
# link the ubirch firmware (specific for the board)
target_link_libraries(ubirch-template ubirch::${BOARD}::firmware)
# create some extra targets for flashing and showing the debug command line
prepare_flash(TARGET ubirch-template)

# copy the config.h.template to config.h in case it is not there; it is ignored by .git!
if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/config.h")
  message(AUTHOR_WARNING "In directory '${CMAKE_CURRENT_SOURCE_DIR}': installing the template config.h, please edit!")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.template ${CMAKE_CURRENT_SOURCE_DIR}/config.h COPYONLY)
endif ()

