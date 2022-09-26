#pragma once

#include <functional>

#include <fruit/fruit.h>

class IAssetGroup
{
public:
    virtual bool IsMotorGroup() const = 0;
};

fruit::Component<std::function<IAssetGroup(int)>> getAssetGroupComponent();
