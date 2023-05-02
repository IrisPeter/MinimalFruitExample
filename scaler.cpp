/*
 * Copyright 2014 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "scaler.h"
#include "multiplier.h"
#include <fruit/macro.h>

#include <iostream>

using fruit::Component;
using fruit::Injector;
using fruit::createComponent;

class ScalerImpl : public Scaler
{
private:
    Multiplier* multiplier;
    double factor;

public:
    explicit ScalerImpl(double dFac, Multiplier* multiplier) : multiplier(multiplier), factor(dFac)
    {
    }

    explicit ScalerImpl(int iFac, Multiplier* multiplier) : multiplier(multiplier), factor(iFac)
    {
    }

    double scale(double x) override
    {
        return multiplier->multiply(x, factor);
    }
};

Component<ScalerFactory, ScalerFactory2> getScalerComponent()
{
    return createComponent()    .registerFactory< std::unique_ptr<ScalerImpl>(fruit::Assisted<double>, Multiplier*)>(
                                        [ ](double n, Multiplier* Multiplier)
                                        {
                                            std::cerr << "Inside factory for doubles\n";
                                            return std::unique_ptr<ScalerImpl>(new ScalerImpl(n, Multiplier));
                                        })
                                .registerFactory< std::unique_ptr<ScalerImpl>(fruit::Assisted<int>, Multiplier*)>(
                                        [ ](int n, Multiplier* Multiplier)
                                        {
                                            std::cerr << "Inside factory for ints\n";
                                            return std::unique_ptr<ScalerImpl>(new ScalerImpl(n, Multiplier));
                                        })
                                .bind<Scaler, ScalerImpl>()
                                .install(getMultiplierComponent);
}
