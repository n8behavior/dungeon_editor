#ifndef DUNGEON_H
#define DUNGEON_H

#include <Qt3DCore/QEntity>

#include <Qt3DExtras/Qt3DWindow>


class Dungeon : public Qt3DCore::QEntity
{
public:
    Dungeon();
};

class DungeonView: public Qt3DExtras::Qt3DWindow
{
public:
    DungeonView();
    void createScene();
};

#endif // DUNGEON_H
