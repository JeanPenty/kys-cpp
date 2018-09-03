#pragma once
#include <vector>
#include "Types.h"

enum
{
    BATTLE_ROLE_COUNT = 4096,                       //战场最大人数
    BATTLEMAP_SAVE_LAYER_COUNT = 2,                 //数据文件存储地图数据层数
    BATTLEMAP_LAYER_COUNT = 8,                      //战场需要地图层数
    BATTLEMAP_COORD_COUNT = 64,                     //战场最大坐标
    BATTLE_ENEMY_COUNT = 20,
};

//这个仅保存战场前两层
struct BattleFieldData2
{
    MAP_INT data[BATTLEMAP_SAVE_LAYER_COUNT][BATTLEMAP_COORD_COUNT * BATTLEMAP_COORD_COUNT];
};

//这个类用来初始化记录，没别的用
class BattleMap
{
private:
    std::vector<BattleInfo> battle_infos_;
    std::vector<BattleFieldData2> battle_field_data2_;
public:
    BattleMap();
    ~BattleMap();

    static BattleMap* getInstance() 
    {
        static BattleMap bm;
        return &bm;
    }
    BattleInfo* getBattleInfo(int i);
    void copyLayerData(int battle_field_id, int layer, MapSquareInt* out);

};

