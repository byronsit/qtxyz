#include "QuaternionAxisEntity.h"
#include "LineEntity.h"

QuaternionAxisEntity::QuaternionAxisEntity(Qt3DCore::QEntity *parent)
    : Qt3DCore::QEntity(parent)
{
    // X-axis (Red)
    auto *xLine = new LineEntity(QVector3D(0, 0, 0), QVector3D(1, 0, 0), this);
    auto *redMaterial = new Qt3DExtras::QPhongMaterial(this);
    redMaterial->setDiffuse(Qt::red);
    redMaterial->setAmbient(QColor(Qt::white));
    xLine->addComponent(redMaterial);

    // Y-axis (Green)
    auto *yLine = new LineEntity(QVector3D(0, 0, 0), QVector3D(0, 1, 0), this);
    auto *greenMaterial = new Qt3DExtras::QPhongMaterial(this);
    greenMaterial->setAmbient(QColor(Qt::white));
    greenMaterial->setDiffuse(Qt::green);
    yLine->addComponent(greenMaterial);

    // Z-axis (Blue)
    auto *zLine = new LineEntity(QVector3D(0, 0, 0), QVector3D(0, 0, 1), this);
    auto *blueMaterial = new Qt3DExtras::QPhongMaterial(this);
    blueMaterial->setAmbient(QColor(Qt::white));
    blueMaterial->setDiffuse(Qt::blue);
    zLine->addComponent(blueMaterial);

    m_globalTransform = new Qt3DCore::QTransform(this);
}

void QuaternionAxisEntity::setRotation(const QQuaternion &rotation)
{
    m_globalTransform->setRotation(rotation);
}
QuaternionAxisEntity::~QuaternionAxisEntity() {}
