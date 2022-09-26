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
};

fruit::Component<std::function<IAssetGroup(int)>> getAssetGroupComponent()
{
	return fruit::createComponent()
		.bind<IAssetGroup, AssetGroupImpl>();
}