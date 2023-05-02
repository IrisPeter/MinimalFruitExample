#pragma once

#include <functional>
#include <memory>

#include <fruit/fruit.h>

class IAssetGroup
{
public:
    virtual ~IAssetGroup() = default;
    virtual bool IsMotorGroup() const = 0;
    virtual int GetGroupId() const = 0;
};

using AssetGroupFactory = std::function<std::unique_ptr<IAssetGroup>(int)>;

fruit::Component<AssetGroupFactory> getAssetGroupComponent();
