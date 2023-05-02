#pragma once

#include <fruit/fruit.h>

#include <functional>
#include <memory>

#include "AssetGroup.h"


class INeedsAssetGroup
{
private:
	std::function<std::unique_ptr<IAssetGroup>(int)> create_group;
public:
	virtual int GetCurrentAssetGroup() const = 0;
	virtual ~INeedsAssetGroup() = default;
};

fruit::Component<INeedsAssetGroup> getNeedsAssetGroupComponent();