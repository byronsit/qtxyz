#ifndef QUATERNIONAXISENTITY_H
#define QUATERNIONAXISENTITY_H



#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <QQuaternion>

class QuaternionAxisEntity : public Qt3DCore::QEntity
{
    Q_OBJECT
public:
    QuaternionAxisEntity(Qt3DCore::QEntity *parent = nullptr);
    ~QuaternionAxisEntity();

    void setRotation(const QQuaternion &rotation);

    Qt3DCore::QTransform *m_globalTransform;

private:
    Qt3DCore::QTransform *m_transform;
};

#endif // QUATERNIONAXISENTITY_H
