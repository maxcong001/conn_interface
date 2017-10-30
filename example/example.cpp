
#include "logger/logger.hpp"
#include "li/connMiddleWare.hpp"
#include "li/transConn.hpp"
#include "li/util.hpp"

int main()
{
    set_log_level(logger_iface::log_level::debug);
    __LOG(error, "hello logger!"
                     << "this is error log");
    __LOG(warn, "hello logger!"
                    << "this is warn log");
    __LOG(info, "hello logger!"
                    << "this is info log");
    __LOG(debug, "hello logger!"
                     << "this is debug log");
    transConnMiddleWare<TOKEN, liConnInfo> test;
    auto ins = test.instance();
    ins->test1();

}
