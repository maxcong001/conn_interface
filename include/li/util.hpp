#pragma once



typedef void* TOKEN;
typedef int length_t;
enum LI_RETURN
{
    LI_SUCCESS = 0,
    LI_FAIL,
    LI_RETURN_MAX

};
enum conn_type
{
    LI_SPFE,
    LI_TAFE,
    LI_SCFE,
    X_CONTAINER,
    LI_PROXY
};
struct liConnInfo
{
    std::string IP;
    std::string Port;
    conn_type type;
};
