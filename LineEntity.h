#ifndef LINEENTITY_H
#define LINEENTITY_H

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCylinderMesh>

class LineEntity : public Qt3DCore::QEntity
{
    Q_OBJECT

public:
    LineEntity(const QVector3D &start, const QVector3D &end,  Qt3DCore::QEntity *parent = nullptr);
    ~LineEntity();

private:
    Qt3DExtras::QCylinderMesh *m_cylinderMesh;
    Qt3DCore::QTransform *m_transform;
    Qt3DExtras::QPhongMaterial *m_material;
};

#endif // LINEENTITY_H
