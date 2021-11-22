#include  <glog/logging.h>

void glog_print(int data)
{
	LOG(INFO) << data;
}