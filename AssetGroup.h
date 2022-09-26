#pragma once

#include <functional>
#include <memory>

#include <fruit/fruit.h>

class IAssetGroup
{
public:
    virtual ~IAssetGroup() = default;
    virtual bool IsMotorGroup() const = 0;
};

fruit::Component<std::function<std::unique_ptr<IAssetGroup>(int)>> getAssetGroupComponent();
