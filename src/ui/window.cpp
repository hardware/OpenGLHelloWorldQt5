#include "window.h"

#include "../objects/scene.h"

#include <QGuiApplication>
#include <QKeyEvent>
#include <QOpenGLContext>
#include <QTimer>

Window::Window(QScreen *screen) : QWindow(screen), m_scene(new Scene)
{
    setSurfaceType(OpenGLSurface);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setMajorVersion(4);
    format.setMinorVersion(3);
    format.setSamples(4);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setOption(QSurfaceFormat::DebugContext);

    resize(800, 600);
    setFormat(format);
    create();

    m_context = new QOpenGLContext;
    m_context->setFormat(format);
    m_context->create();

    m_scene->setContext(m_context);

    initializeGL();

    connect(this, SIGNAL(widthChanged(int)), this, SLOT(resizeGL()));
    connect(this, SIGNAL(heightChanged(int)), this, SLOT(resizeGL()));
    resizeGL();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(16); // ~60Hz (f = 1 / 16.10^-3)
}

Window::~Window() {}

void Window::initializeGL()
{
    m_context->makeCurrent(this);
    m_funcs = m_context->versionFunctions<QOpenGLFunctions_3_3_Core>();

    if ( ! m_funcs ) {
        qWarning("Could not obtain OpenGL versions object");
        exit(1);
    }

    m_funcs->initializeOpenGLFunctions();
    m_scene->initialize();
}

void Window::paintGL()
{
    m_context->makeCurrent(this);
    m_scene->render();
    m_context->swapBuffers(this);
}

void Window::resizeGL()
{
    m_context->makeCurrent(this);
    m_scene->resize(width(), height());
}

void Window::updateGL()
{
    m_scene->update(0.0f);
    paintGL();
}
