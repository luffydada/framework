AUX_SOURCE_DIRECTORY(. SRCS)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/sdk/include)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/sdk/lib)

ADD_EXECUTABLE(mediaplayer ${SRCS})
SET_TARGET_PROPERTIES(mediaplayer PROPERTIES OUTPUT_NAME "dd_mediaplayer")

TARGET_LINK_LIBRARIES(mediaplayer dandan)

# 设置输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/release/bin)
