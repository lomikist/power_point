#ifndef QT_GRAPHIC_WRAPPER_HPP
#define QT_GRAPHIC_WRAPPER_HPP

#include "qgraphicsscene.h"
#include "icanvas.hpp"

namespace core 
{

class GraphicsSceneCanvas : public ICanvas 
{
private:
    QGraphicsScene* _scene;
public:
    GraphicsSceneCanvas(QGraphicsScene* s); 
    void draw(const RectPtr& rect_shape) override;
    void draw(const CirclePtr& circle_shape) override;
};

}
#endif // !QT_GRAPHIC_WRAPPER_HPP
