#pragma once
#include "li/util.hpp"
#include "logger/logger.hpp"

/*
    IM_trans_event.TransNotifyPacketArrived = IM_onReceived;
    IM_trans_event.TransNotifyNewConnection = IM_onNewConnNotifyCB;
    IM_trans_event.TransNotifyConnected = IM_onConnectNotifyCB;
    IM_trans_event.TransNotifyConnectionClosed = IM_onCloseNotifyCB;
    IM_trans_event.TransNotifyConnectError = IM_onConnectErrorNotifyCB;
    IM_trans_event.TransNotifyListenError = IM_onListenErrorNotifyCB;
    // The TransNotifyTimeout call back function is required if and only if the
    // Translib user want to use TransSetTimerMS() API to set a timer. As
    // IM always uses TransSetTimerDirectMS()
    // to set timer, there is no need to provide such a call back function here.
    IM_trans_event.TransNotifyTimeout = NULL;
    IM_trans_event.TransNotifySocketError = IM_onSocketError;
    IM_trans_event.TransNotifyUDPPacketArrived = NULL;
    */

template <typename connInd, typename connInfo>
class transConnMiddleWare : public ConnMiddleWare<connInd, connInfo>
{
  public:
    typedef connInd conn_ind_t;
    typedef connInfo conn_info_t;
    transConnMiddleWare(){
        /*
        // for client
        memset(&IM_trans_event, 0, sizeof(TransEventT));
        IM_trans_event.TransNotifyPacketArrived = NULL;
        IM_trans_event.TransNotifyNewConnection = NULL;
        IM_trans_event.TransNotifyConnected = NULL;
        IM_trans_event.TransNotifyConnectionClosed = NULL;
        IM_trans_event.TransNotifyConnectError = NULL;
        IM_trans_event.TransNotifyListenError = NULL;
        IM_trans_event.TransNotifyTimeout = NULL;
        IM_trans_event.TransNotifySocketError = NULL;
        IM_trans_event.TransNotifyUDPPacketArrived = NULL;

        // for server
        memset(&IM_trans_event, 0, sizeof(TransEventT));
        IM_trans_event.TransNotifyPacketArrived = NULL;
        IM_trans_event.TransNotifyNewConnection = NULL;
        IM_trans_event.TransNotifyConnected = NULL;
        IM_trans_event.TransNotifyConnectionClosed = NULL;
        IM_trans_event.TransNotifyConnectError = NULL;
        IM_trans_event.TransNotifyListenError = NULL;
        IM_trans_event.TransNotifyTimeout = NULL;
        IM_trans_event.TransNotifySocketError = NULL;
        IM_trans_event.TransNotifyUDPPacketArrived = NULL;
        */
    };
    virtual ~transConnMiddleWare(){};
    static transConnMiddleWare<connInd, connInfo> *instance()
    {
        __LOG(debug, "get trans middleware instance");
        static transConnMiddleWare<connInd, connInfo> *ins = new transConnMiddleWare<connInd, connInfo>();
        return ins;
    }
    /*-------------------------------------------------------------------------------------*/
    // common
    LI_RETURN send(connInd server_ind, TOKEN _token, void *msg, length_t len){};
    LI_RETURN close(connInd ind){};

    void test()
    {
        __LOG(debug, "test");
    }

    void test1()
    {
        __LOG(debug, "test1");
        (this->instance())->test();
    }
    /*-------------------------------------------------------------------------------------*/
    // as server
    LI_RETURN listen(connInd &ind, connInfo info){};
    // server callback def
    int onServerNewConnCb(connInd session_ind, TOKEN old_token, TOKEN *new_token, connInfo *info)
    {
        __LOG(debug, "onServerNewConnCb");
    };
    int OnServerReceiveCb(connInd session_ind, TOKEN _token, void *msg, length_t len)
    {
        __LOG(debug, "OnServerReceiveCb");
    };
    int OnServerConnClosedCb(connInd session_ind, TOKEN _token, int errorNuber){};
    int onServerListenErrorCb(connInd session_ind, TOKEN _token, int errorNuber){};
    int OnServerSocketErrorCb(connInd session_ind, TOKEN _token, int errorNuber){};

    /*-------------------------------------------------------------------------------------*/
    // as client
    LI_RETURN connect(connInd &ind, connInfo info){};
    // client callback def
    int onClientReceiveCb(connInd ind, TOKEN _token, void *msg, length_t len){};
    int onClinetConnectedCb(connInd ind, TOKEN _token){};
    int OnClientConnClosedCb(connInd ind, TOKEN _token, int errorNumber){};
    int onClientConnErrorCb(connInd ind, TOKEN _token, int errorNumber){};
    int onClientSocketErrorCb(connInd ind, TOKEN _token, int errorNumber){};

    /*-------------------------------------------------------------------------------------*/
    // data
    /*
    // Contains callback functions of translib
    TransEventT li_trans_event_client;
    TransEventT li_trans_event_server;
    // Socket options of translib
    TransSockOpts li_trans_sock_opts;
    */
};
