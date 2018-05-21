// blackhart.editor headers
#include "BkViewer.hpp"

// blackhart headers.
#include "..\..\blackhart\export\cpp\Blackhart.hpp"

// ~~~~~ Def(PUBLIC) ~~~~~

static struct BkOrbitalCamera   g_camera;

BkViewer::BkViewer(QWidget* parent) :
    QOpenGLWidget{ parent }
{
}

BkViewer::~BkViewer()
{
    makeCurrent();
    BkUninitialize();
}

// ~~~~~ Def(INTERNAL) ~~~~~

void    BkViewer::initializeGL()
{
    // Initialize Blackhart
    BkInitialize();
    // Initialize Camera
    BkOrbitalCamera_Initialize(&g_camera);
    struct BkPoint3 const to = BkPoint3_FromXYZ(BK_REAL(0.0), BK_REAL(0.0), BK_REAL(0.0));
    BkOrbitalCamera_SetTarget(&g_camera, &to);
    BkOrbitalCamera_SetRadius(&g_camera, BK_REAL(5));
}

void    BkViewer::paintGL()
{
    BkRender(&(g_camera.base));
}

void    BkViewer::resizeGL(int width, int height)
{
    g_camera.base.projection = BkProjection_Perspective(BK_REAL(45), BK_REAL(width) / BK_REAL(height), BK_REAL(0.1), BK_REAL(1000));
}