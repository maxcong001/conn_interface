
#include "logger/logger.hpp"
#include "li/connMiddleWare.hpp"
#include "li/transConn.hpp"
#include "li/util.hpp"
#include "li/connManager.hpp"

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
    auto ins1 = transConnMiddleWare<TOKEN, liConnInfo>::instance();
    ins1->test1();

    connManager<transConnMiddleWare<TOKEN, liConnInfo>, liServiceDiscovery<liConnInfo>> manager_test;
    manager_test.test();

}
