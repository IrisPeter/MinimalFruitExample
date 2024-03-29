// MinimalFruitExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
// The only purpose of this project is to show things that you would think would be simple to setup, so that
// you can move from compile errors to full build of project with zero errors

#include "NeedsAssetGroup.h"
#include "AssetGroup.h"
#include "scaler.h"
#include <memory>
#include <iostream>

using fruit::Injector;

int main(int argc, char* argv[], char* other_parameters[])
{
    int ret = 0;

    Injector<ScalerFactory, ScalerFactory2> injector(getScalerComponent);
    ScalerFactory scalerFactory(injector);

    std::unique_ptr<Scaler> scaler = scalerFactory(12.1);
    std::cout << scaler->scale(3) << std::endl;


    ScalerFactory2 integerScalerFactory(injector);

    int i = 4;

    std::unique_ptr<Scaler> scaler2 = integerScalerFactory(i);
    std::cout << scaler2->scale(3) << std::endl;


    // Why does this not call the int based factory?
    std::unique_ptr<Scaler> scaler3 = scalerFactory(i);
    std::cout << scaler3->scale(3) << std::endl;

    return ret;
}
