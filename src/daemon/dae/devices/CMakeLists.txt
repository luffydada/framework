AUX_SOURCE_DIRECTORY(. SRCS)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/sdk/include)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/sdk/lib)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/release/lib)

ADD_EXECUTABLE(dae ${SRCS})
SET_TARGET_PROPERTIES(dae PROPERTIES OUTPUT_NAME "dd_dae")

TARGET_LINK_LIBRARIES(dae dandan)
TARGET_LINK_LIBRARIES(dae dd_daeinterface)

# 设置输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/release/bin)

ADD_DEPENDENCIES(dae daeinterface)
