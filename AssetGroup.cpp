#include "AssetGroup.h"

using fruit::Component;
using fruit::Injector;
using fruit::createComponent;

class AssetGroupImpl : public IAssetGroup
{
private:
	int m_group;

public:
	INJECT(AssetGroupImpl(ASSISTED(int) group)) : m_group(group) {}

	// Inherited via IAssetGroup
	bool IsMotorGroup() const override
	{
		return false;
	}

	// Inherited via IAssetGroup
	int GetGroupId() const override
	{
		return m_group;
	}
};

fruit::Component<AssetGroupFactory> getAssetGroupComponent()
{
	return fruit::createComponent()
		.bind<IAssetGroup, AssetGroupImpl>();
}