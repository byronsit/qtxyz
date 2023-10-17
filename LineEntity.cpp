#include "LineEntity.h"

LineEntity::LineEntity(const QVector3D &start, const QVector3D &end, Qt3DCore::QEntity *parent)
    : Qt3DCore::QEntity(parent),
    m_cylinderMesh(new Qt3DExtras::QCylinderMesh(this)),
    m_transform(new Qt3DCore::QTransform(this)),
    m_material(new Qt3DExtras::QPhongMaterial(this))
{
    QVector3D dir = end - start;
    float length = dir.length();

    m_cylinderMesh->setRadius(0.1f); // you can adjust the thickness by setting a different radius value
    m_cylinderMesh->setLength(length);
    m_cylinderMesh->setRings(100);
    m_cylinderMesh->setSlices(20);

    m_transform->setTranslation((start + end) * 0.5);
    m_transform->setRotation(QQuaternion::rotationTo(QVector3D(0, 1, 0), dir.normalized()));
    qDebug()<<m_transform->rotation();
    qDebug()<<m_transform->translation();

    addComponent(m_cylinderMesh);
    addComponent(m_transform);
    addComponent(m_material);
}

LineEntity::~LineEntity() {}
