#include <box2d/box2d.h>

namespace CruZ
{
class BodyFactory
{
  public:
    BodyFactory(b2World &world);
    b2Body *CreateCircle(float r, b2BodyType bodyType);
    b2Body *CreateBody(b2BodyDef &);
    void DestroyBody(b2Body &body);

  private:
    b2World *m_world;
};
} // namespace CruZ

#include "Instances.h"