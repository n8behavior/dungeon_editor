#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtGui/QSessionManager>

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>

#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DRender/QRenderAspect>

#include <Qt3DInput/QInputAspect>

#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/Qt3DWindow>

#include "dungeon.hpp"
/*
class DungeonModifier
{
    //Q_OBJECT

public:
    DungeonModifier(Dungeon&);

    void load_dungeon(const QString &dungeon_name);

private slots:
    void new_dungeon();
    void open();
    bool save();
    bool save_as();
    void about();
    void dungeon_was_modified();
#ifndef QT_NO_SESSIONMANAGER
    void commit_data(QSessionManager &);
#endif

private:
    void create_editor_actions();
    void create_editor_status_bar();
    void create_editor_dock_widgets();
    void read_editor_settings();
    void write_editor_settings();
    bool maybe_save_dungeon();
    bool save_dungeon(const QString &dungeon_name);
    void set_current_dungeon(const QString &dungeon_name);
    Qt3DCore::QEntity *createScene();

    Dungeon& dungeon;
    QString current_dungeon;
    QListWidget* dungeon_properties;
};
*/
#endif // MAINWINDOW_H
