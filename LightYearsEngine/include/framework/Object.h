#pragma once

namespace ly
{

    class Object
    {
    public:
        Object();
        ~Object();

        void Destroy();

        bool PendingDestroy() { return mPendingToDestroy; };

    private:
        bool mPendingToDestroy;
    };

}