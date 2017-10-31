#pragma once
#include "li/util.hpp"
#include "li/serviceDiscovery.hpp"
#include "li/connMiddleWare.hpp"
#include "li/transConn.hpp"
#include <boost/bind.hpp>
template <typename connectionMiddleWare, typename serviceDiscovery>
class connManager
{
  public:
    typedef typename connectionMiddleWare::conn_ind_t li_conn_ind_t;
    typedef typename connectionMiddleWare::conn_info_t li_conn_info_t;
    typedef typename serviceDiscovery::connList spfeList;

    bool init()
    {
        // 1. set connection inc/dec callback for service discovery calss
        servDiscov.setOnSpfeIncCb(boost::bind(&connManager<connectionMiddleWare, serviceDiscovery>::onSpfeInc, this));
        servDiscov.setOnSpfeDecCb(boost::bind(&connManager<connectionMiddleWare, serviceDiscovery>::onSpfeDec, this));
        // 2. App logic for example
        for (auto conn_info : (servDiscov.getSpfeInfo()))
        {
            li_conn_ind_t ind;
            (servDiscov.instance())->connect(&ind, conn_info);
            spfe_conn_ind_list.push(ind);
        }
        for (auto conn_info : (servDiscov.getXContainerInfo()))
        {
            li_conn_ind_t ind;
            (servDiscov.instance())->connect(&ind, conn_info);
            x_conn_ind_list.push(ind);
        }
    }
    void test()
    {
        __LOG(debug, "");
    }
    

    void onSpfeInc(spfeList list)
    {
    }
    void onSpfeDec(spfeList list)
    {
    }

    serviceDiscovery servDiscov;
    connectionMiddleWare liConn;

    std::list<li_conn_ind_t> spfe_conn_ind_list;
    std::list<li_conn_ind_t> scfe_conn_ind_list;
    std::list<li_conn_ind_t> tafe_conn_ind_list;
    std::list<li_conn_ind_t> x_conn_ind_list;
    std::list<li_conn_ind_t> proxy_conn_ind_list;
};
