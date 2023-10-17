#include <QApplication>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DRender/QCamera>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include "QuaternionAxisEntity.h"
#include <QTimer>

int main2(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 创建Qt3D窗口
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();

    // 创建一个QWidget容器并将Qt3D窗口添加到此容器中
    QWidget *container = QWidget::createWindowContainer(view);

    // 创建主窗口和布局，将容器添加到布局中
    QWidget *mainWindow = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout(mainWindow);
    layout->addWidget(container);
    mainWindow->setWindowTitle("Quaternion Axis Viewer");

    // 创建一个Qt3D的场景根实体
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;

    // 添加QuaternionAxisEntity到场景
    QuaternionAxisEntity *axisEntity = new QuaternionAxisEntity(rootEntity);
    axisEntity->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45)); // 示例：绕x轴旋转45度

    // 设置摄像机
    Qt3DRender::QCamera *camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(5.0f, 5.0f, 5.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    // 使用QOrbitCameraController来控制摄像机
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setLinearSpeed(50.0f);
    camController->setLookSpeed(180.0f);
    camController->setCamera(camera);

    // 设置场景的根实体
    view->setRootEntity(rootEntity);

    // 调整并显示主窗口
    mainWindow->resize(800, 600);
    mainWindow->show();

    return app.exec();
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 创建Qt3D窗口
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();

    // 创建一个QWidget容器并将Qt3D窗口添加到此容器中
    QWidget *container = QWidget::createWindowContainer(view);

    // 创建主窗口和布局，将容器添加到布局中
    QWidget *mainWindow = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout(mainWindow);
    layout->addWidget(container);
    mainWindow->setWindowTitle("Quaternion Axis Viewer");

    // 创建一个Qt3D的场景根实体
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;

    // 添加QuaternionAxisEntity到场景
    QuaternionAxisEntity *axisEntity = new QuaternionAxisEntity(rootEntity);
    axisEntity->addComponent(axisEntity->m_globalTransform);  // Make sure to add the global transform to the entity

    // 设置摄像机
    Qt3DRender::QCamera *camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(1.0f, 5.0f, 5.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    // 使用QOrbitCameraController来控制摄像机
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setLinearSpeed(50.0f);
    camController->setLookSpeed(180.0f);
    camController->setCamera(camera);

    // 设置场景的根实体
    view->setRootEntity(rootEntity);

    // 创建动画效果
    float angle = 0.0f;
    QTimer *timer = new QTimer(mainWindow);
    QObject::connect(timer, &QTimer::timeout, [&]() {
        angle += 1.0f;
        if (angle >= 360.0f)
            angle = 0.0f;

        QQuaternion rotation = QQuaternion::fromAxisAndAngle(QVector3D(1, 1, 1), angle);  // Change this if needed
        axisEntity->setRotation(rotation);
    });
    timer->start(16);  // About 60fps

    // 调整并显示主窗口
    mainWindow->resize(800, 600);
    mainWindow->show();

    return app.exec();
}
