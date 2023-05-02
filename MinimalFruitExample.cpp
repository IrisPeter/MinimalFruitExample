// MinimalFruitExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
// The only purpose of this project is to show things that you would think would be simple to setup, so that
// you can move from compile errors to full build of project with zero errors

#include "NeedsAssetGroup.h"
#include "AssetGroup.h"

int main(int argc, char* argv[], char* other_parameters[])
{
    int ret = 0;

    // Create Group using integer

    // Non DI Code:
    // auto someGroup = CAssetGroup::Create(12);


    /*

    fruit::Injector<Iris::BusinessRules::Taxation::ILicenceInformation> injector(getLicenceComponent);

	Iris::BusinessRules::Taxation::ILicenceInformation::Ptr licensePtr(injector);

	WPARAM one = 1;
	LPARAM two = 2;

	auto wideParam = one;
	auto longParam = two;

	bool SUT = licensePtr->GetIsLicensedForAutoMail() ;
    */
    fruit::Injector<INeedsAssetGroup> injector(getNeedsAssetGroupComponent);


    INeedsAssetGroup* needsAssetGroupPtr(injector);

    auto res = needsAssetGroupPtr->GetCurrentAssetGroup();

   /* fruit::Injector<AssetGroupFactory> injector(getAssetGroupComponent);
    AssetGroupFactory groupFactory(injector);

    std::unique_ptr<IAssetGroup> group = groupFactory(512);*/

    return ret;
}
