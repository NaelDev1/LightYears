#include "framework/Object.h"
#include "Core.h"

namespace ly
{
    Object::Object()
        : mPendingToDestroy{false}
    {
    }

    Object::~Object()
    {
    }

    void Object::Destroy()
    {
        mPendingToDestroy = true;
        LOG("The object is destroid");
    }
}