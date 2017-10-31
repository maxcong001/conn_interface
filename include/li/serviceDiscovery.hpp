#pragma once
#include <list>
#include <boost/function.hpp>
#include <li/util.hpp>

template <typename connInfo>
class liServiceDiscovery
{
public:
  typedef std::list<connInfo> connList;
  typedef boost::function<void(connList)> connInfoChgCb;

  connList getSpfeInfo();
  connList getXContainerInfo();
  bool setOnSpfeIncCb(connInfoChgCb cb) { spfe_conn_inc_cb = cb; };
  bool setOnSpfeDecCb(connInfoChgCb cb) { spfe_conn_dec_cb = cb; };

  connList conn_info_x_container;
  connList conn_info_spfe;

  connInfoChgCb spfe_conn_inc_cb;
  connInfoChgCb spfe_conn_dec_cb;
  /*
  // optional todo
  connList getScfeInfo(){};
  connList getTafeInfo(){};
  connList getProxyInfo(){};
  connList getFEsInfo(){};
  connList conn_info_scfe;
  connList conn_info_tafe;
  connList conn_info_proxy;
  // end optional
  */
};