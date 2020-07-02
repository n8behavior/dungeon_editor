#include <QtCore/QPropertyAnimation>

#include <QtGui/QVector3D>
#include <QtGui/QColor>
#include <QtGui/QRgb>

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>

#include <Qt3DRender/QCamera>
#include <Qt3DRender/QMaterial>
#include <Qt3DRender/QPointLight>

#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QFirstPersonCameraController>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QTorusMesh>

#include "dungeon.hpp"
#include "orbit_transform_controller.hpp"

Dungeon::Dungeon() {}

DungeonView::DungeonView() {
}

void DungeonView::createScene() {
    defaultFrameGraph()->setClearColor(QColor(QRgb(0xbe3000)));

    // Root entity
    auto* root_entity = new Qt3DCore::QEntity();

    // Camera
    auto* camera = this->camera();
    camera->lens()->setPerspectiveProjection(55.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    //camera->lens()->setOrthographicProjection(-10.0f,10.0f,-10.0f,10.0f,0.1f,30.0f);
    camera->setPosition(QVector3D(0, 0, 60.0f));
    camera->setUpVector(QVector3D(0, 1, 0));
    camera->setViewCenter(QVector3D(0, 0, 0));

    auto* light_entity = new Qt3DCore::QEntity(root_entity);
    auto* point_light = new Qt3DRender::QPointLight(light_entity);
    point_light->setColor("white");
    point_light->setIntensity(1);
    light_entity->addComponent(point_light);
    auto* light_transform = new Qt3DCore::QTransform(light_entity);
    light_transform->setTranslation(camera->position());
    light_entity->addComponent(light_transform);

    // For camera controls
    auto* camera_controller = new Qt3DExtras::QFirstPersonCameraController(root_entity);
    camera_controller->setCamera(camera);

    // Scenemodifier
    //auto* dungeon_editor = new DungeonEditor(dungeon);

    // Set root object of the scene
    setRootEntity(root_entity);

    auto *material = new Qt3DExtras::QPhongMaterial(root_entity);

    Qt3DCore::QEntity *torusEntity = new Qt3DCore::QEntity(root_entity);
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

    Qt3DCore::QEntity *sphereEntity = new Qt3DCore::QEntity(root_entity);
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
