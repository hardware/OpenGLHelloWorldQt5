#ifndef SCENE_H
#define SCENE_H

#include "abstractscene.h"

#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

class Scene : public AbstractScene
{

public:
    Scene();

    virtual void initialize();
    virtual void update(float t);
    virtual void render();
    virtual void resize(int w, int h);

private:
    void prepareShaderProgram();
    void prepareVertexBuffers();

    QOpenGLShaderProgram     m_shaderProgram;
    QOpenGLBuffer            m_vertexPositionBuffer;
    QOpenGLBuffer            m_vertexColorBuffer;
    QOpenGLVertexArrayObject m_vao;

};

#endif // SCENE_H
