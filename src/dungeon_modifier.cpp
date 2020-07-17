
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

#include "dungeon.hpp"
#include "orbit_transform_controller.hpp"

#include "dungeon_modifier.hpp"
/*
DungeonModifier::DungeonModifier(Dungeon& d)
    : dungeon(d)
{
}

void DungeonModifier::load_dungeon(const QString &dungeon_name) {
    qInfo() << "Called";
    QFile file(dungeon_name);
    //if (!file.open(QFile::ReadOnly | QFile::Text)) {
    //    QMessageBox::warning(this, tr("Application"),
    //                         tr("Cannot read file %1:\n%2.")
    //                         .arg(QDir::toNativeSeparators(dungeon_name), file.errorString()));
        return;
    }

    //QTextStream in(&file);
#ifndef QT_NO_CURSOR
    //QGuiApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    // TODO Serialize dungeon
    //view->setPlainText(in.readAll());
#ifndef QT_NO_CURSOR
    //QGuiApplication::restoreOverrideCursor();
#endif

    //set_current_dungeon(dungeon_name);
    //statusBar()->showMessage(tr("File loaded"), 2000);
}

//void DungeonEditor::closeEvent(QCloseEvent *event) {
//    qInfo() << "Called";
//    if (maybe_save_dungeon()) {
//        write_editor_settings();
//        event->accept();
//    } else {
//        event->ignore();
//    }
//}

void DungeonModifier::new_dungeon() {
    qInfo() << "Called";
    if (maybe_save_dungeon()) {
        // TODO
        //view->clear();
        set_current_dungeon(QString());
    }
}

void DungeonModifier::open() {
    qInfo() << "Called";
    if (maybe_save_dungeon()) {
//        QString dungeon_name = QFileDialog::getOpenFileName(this);
//        if (!dungeon_name.isEmpty())
//            load_dungeon(dungeon_name);
    }
}


bool DungeonModifier::save() {
    qInfo() << "Called";
    if (current_dungeon.isEmpty())
        return save_as();
    else
        return save_dungeon(current_dungeon);
}

bool DungeonModifier::save_as() {
    qInfo() << "Called";
//    QFileDialog dialog(this);
//    dialog.setWindowModality(Qt::WindowModal);
//    dialog.setAcceptMode(QFileDialog::AcceptSave);
//    if (dialog.exec() != QDialog::Accepted)
//        return false;
    return true; // save_dungeon(dialog.selectedFiles().first());
}

void DungeonModifier::about() {
    qInfo() << "Called";
//    QMessageBox::about(this, tr("What?"), tr("Get back to work!"));
}

void DungeonModifier::dungeon_was_modified() {
    qInfo() << "Called";
    // TODO: setWindowModified(view->isModified());
}

void DungeonModifier::commit_data(QSessionManager &) {
    qInfo() << "Called";
}

void DungeonModifier::create_editor_actions() {
    qInfo() << "Called";

}

void DungeonModifier::create_editor_status_bar() {
    qInfo() << "Called";
    statusBar()->showMessage(tr("Ready"));
}

void DungeonModifier::create_editor_dock_widgets() {
    qInfo() << "Called";
    QDockWidget *dock = new QDockWidget(tr("Dungeon Properties"), this);
    dock->setAllowedAreas(Qt::DockWidgetArea::AllDockWidgetAreas);
    dungeon_properties = new QListWidget(dock);
    dungeon_properties->addItems(QStringList()
                                 << "Height, 64"
                                 << "Width, 64"
                                 << "Wall Cubes, 13");
    dock->setWidget(dungeon_properties);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void DungeonModifier::read_editor_settings() {
    qInfo() << "Called";
    QSettings settings;
    const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty()) {
        const QRect available_geometry = screen()->availableGeometry();
        resize(available_geometry.width() / 3, available_geometry.height() / 2);
        move((available_geometry.width() - width()) / 2,
             (available_geometry.height() - height()) / 2);
    } else {
        restoreGeometry(geometry);
    }
}

void DungeonModifier::write_editor_settings() {
    qInfo() << "Called";
    QSettings settings;
    settings.setValue("geometry", saveGeometry());
}

bool DungeonModifier::maybe_save_dungeon() {
    qInfo() << "Called";
    // TODO: make sure dungeon is saved or user doesn't care about changings
    //if (!view->isModified())
    //    return true;
    //const QMessageBox::StandardButton ret
    //        = QMessageBox::warning(this, tr("Application"),
    //                   tr("The dungeon has been modified.\n"
    //                      "Do you want to save your changes?"),
    //                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    //switch (ret) {
    //case QMessageBox::Save:
    //    return save();
    //case QMessageBox::Cancel:
    //    return false;
    //default:
    //    break;
    //}
    return true;
}

bool DungeonModifier::save_dungeon(const QString &dungeon_name) {
    qInfo() << "Called";
    // TODO Persistence
    //QString error_message;

    //QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    //QSaveFile dungeon_data(dungeon_name);
    //if (dungeon_data.open(QFile::WriteOnly | QFile::Text)) {
    //    QTextStream out(&dungeon_data);
    //    out << view->toPlainText();
    //    if (!dungeon_data.commit()) {
    //        error_message = tr("Cannot write dungeon %1:\n%2.")
    //                       .arg(QDir::toNativeSeparators(dungeon_name), dungeon_data.errorString());
    //    }
    //} else {
    //    error_message = tr("Cannot open dungeon %1 for writing:\n%2.")
    //                   .arg(QDir::toNativeSeparators(dungeon_name), dungeon_data.errorString());
    //}
    //QGuiApplication::restoreOverrideCursor();

    //if (!error_message.isEmpty()) {
    //    QMessageBox::warning(this, tr("Application"), error_message);
    //    return false;
    //}

    //set_current_dungeon(dungeon_name);
    //statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void DungeonModifier::set_current_dungeon(const QString &dungeon_name) {
    qInfo() << "Called";
    current_dungeon = dungeon_name;
    // TODO: view->setModified(false);
    setWindowModified(false);

    // TODO: doesn't work with setWindowTitle() above
    if (current_dungeon.isEmpty())
        setWindowFilePath("dungeon1.txt");
    else
        setWindowFilePath(current_dungeon);
}

Qt3DCore::QEntity *DungeonModifier::createScene()
{
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;

    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);

    Qt3DCore::QEntity *torusEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QTorusMesh *torusMesh = new Qt3DExtras::QTorusMesh;
    torusMesh->setRadius(5);
    torusMesh->setMinorRadius(1);
    torusMesh->setRings(100);
    torusMesh->setSlices(20);

    Qt3DCore::QTransform *torusTransform = new Qt3DCore::QTransform;
    torusTransform->setScale3D(QVector3D(1.5, 1, 0.5));
    torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45.0f));

    torusEntity->addComponent(torusMesh);
    torusEntity->addComponent(torusTransform);
    torusEntity->addComponent(material);

    Qt3DCore::QEntity *sphereEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh;
    sphereMesh->setRadius(3);
    sphereMesh->setGenerateTangents(true);

    Qt3DCore::QTransform *sphereTransform = new Qt3DCore::QTransform;
    OrbitTransformController *controller = new OrbitTransformController(sphereTransform);
    controller->setTarget(sphereTransform);
    controller->setRadius(20.0f);

    QPropertyAnimation *sphereRotateTransformAnimation = new QPropertyAnimation(sphereTransform);
    sphereRotateTransformAnimation->setTargetObject(controller);
    sphereRotateTransformAnimation->setPropertyName("angle");
    sphereRotateTransformAnimation->setStartValue(QVariant::fromValue(0));
    sphereRotateTransformAnimation->setEndValue(QVariant::fromValue(360));
    sphereRotateTransformAnimation->setDuration(10000);
    sphereRotateTransformAnimation->setLoopCount(-1);
    sphereRotateTransformAnimation->start();

    sphereEntity->addComponent(sphereMesh);
    sphereEntity->addComponent(sphereTransform);
    sphereEntity->addComponent(material);
}
*/
