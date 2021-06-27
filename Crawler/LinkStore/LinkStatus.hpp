#ifndef LinkStatus_hpp
#define LinkStatus_hpp
//enumy sovorakan tip e vonc vor classy, ira mej grvac en popoxakannery,
// u sa takic darnalu e class static popoxakannerov u W arjeqy linlu e 0, L=1, E=2
enum class LinkStatus
{
    WAITING = 0,
    LOADED = 1,
    ERROR = 2
};

#endif