#include <iostream>

#include  <glog/logging.h>

#include "cmake_test2.h"


int main(int argc, char **argv) {
	FLAGS_logtostderr = true;
	//FLAGS_alsologtostderr = true;

	google::InitGoogleLogging(argv[0]);
	FLAGS_log_dir = "./";

	glog_print(500);  //调用src文件夹中的函数

	LOG(INFO) << "INFO";
	LOG(WARNING) << "WARNING";
	DLOG(ERROR) << "ERROR";
	//LOG(FATAL) << "FATAL";   //执行则退出程序
#if ctest
	DCHECK(!FLAGS_logtostderr) << "DCHECK";  //检查括号内部为真，否则退出程序
#endif
	DLOG_IF(INFO, true) << "DLOG_IF";    //条件成立打印
	DCHECK_EQ(FLAGS_alsologtostderr,0) << "DCHECK_EQ";  ////检查括号内部相等，否则退出程序

	return 0;
}