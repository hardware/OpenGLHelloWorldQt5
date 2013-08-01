#ifndef WINDOW_H
#define WINDOW_H

#include <QWindow>
#include <QScopedPointer>
#include <QOpenGLFunctions_3_3_Core>

class AbstractScene;
class QOpenGLContext;

class Window : public QWindow
{
    Q_OBJECT

public:
    Window(QScreen* screen = 0);
    ~Window();

private:
    void initializeGL();
    
protected slots:
    void resizeGL();
    void paintGL();
    void updateGL();

private:
    QOpenGLContext* m_context;
    QScopedPointer<AbstractScene> m_scene;
    QOpenGLFunctions_3_3_Core* m_funcs;
    
};

#endif // WINDOW_H
