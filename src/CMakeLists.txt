# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library (cmake_test2  ${DIR_LIB_SRCS})

# 指定 cmake_test2 库的安装路径
install (TARGETS cmake_test2 DESTINATION lib)
install (FILES cmake_test2.h DESTINATION include)

