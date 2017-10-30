#pragma once
#include "li/util.hpp"
template <typename connInd, typename connInfo>
class ConnMiddleWare
{
  public:
    ConnMiddleWare(){};
    virtual ~ConnMiddleWare(){};
    /*-------------------------------------------------------------------------------------*/
    // common
    virtual LI_RETURN send(connInd server_ind, TOKEN _token, void *msg, length_t len) = 0;
    virtual LI_RETURN close(connInd ind) = 0;

    /*-------------------------------------------------------------------------------------*/
    // as server
    virtual LI_RETURN listen(connInd &ind, connInfo info) = 0;

    // server callback def
    virtual int onServerNewConnCb(connInd session_ind, TOKEN old_token, TOKEN *new_token, connInfo *info) = 0;
    virtual int OnServerReceiveCb(connInd session_ind, TOKEN _token, void *msg, length_t len) = 0;
    virtual int OnServerConnClosedCb(connInd session_ind, TOKEN _token, int errorNuber) = 0;
    virtual int onServerListenErrorCb(connInd session_ind, TOKEN _token, int errorNuber) = 0;
    virtual int OnServerSocketErrorCb(connInd session_ind, TOKEN _token, int errorNuber) = 0;

    /*-------------------------------------------------------------------------------------*/
    // as client
    virtual LI_RETURN connect(connInd &ind, connInfo info) = 0;

    // client callback def
    virtual int onClientReceiveCb(connInd ind, TOKEN _token, void *msg, length_t len) = 0;
    virtual int onClinetConnectedCb(connInd ind, TOKEN _token) = 0;
    virtual int OnClientConnClosedCb(connInd ind, TOKEN _token, int errorNumber) = 0;
    virtual int onClientConnErrorCb(connInd ind, TOKEN _token, int errorNumber) = 0;
    virtual int onClientSocketErrorCb(connInd ind, TOKEN _token, int errorNumber) = 0;

    /*-------------------------------------------------------------------------------------*/
    // data
    // used when close server
    connInd server_indicator;
    // server connection list
    //???
    // client connection list
    //???
};