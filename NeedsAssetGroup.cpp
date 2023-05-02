#include "NeedsAssetGroup.h"

class NeedsAssetGroupImpl : public INeedsAssetGroup
{
private:
	std::function<std::unique_ptr<IAssetGroup>(int)> create_group;
public:
	INJECT(NeedsAssetGroupImpl(std::function<std::unique_ptr<IAssetGroup>(int)> create_groupFactory)) : create_group(create_groupFactory)
	{
	}

	// Inherited via INeedsAssetGroup
	virtual int GetCurrentAssetGroup() const override
	{
		std::unique_ptr<IAssetGroup> group = create_group(5);

		return group->GetGroupId();
	}
};


fruit::Component<INeedsAssetGroup> getNeedsAssetGroupComponent()
{
	return fruit::createComponent()
		.bind<INeedsAssetGroup, NeedsAssetGroupImpl>()
		.install(getAssetGroupComponent);
}
