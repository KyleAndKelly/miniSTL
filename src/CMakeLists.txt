AUX_SOURCE_DIRECTORY(. SRC_LIST)
# LINK_LIBRARIES("/mnt/d/Project/Cpp_Project/miniSTL/build/base/libbaseLib.a")
ADD_EXECUTABLE(stlTest ${SRC_LIST})


TARGET_LINK_LIBRARIES(stlTest pthread)
