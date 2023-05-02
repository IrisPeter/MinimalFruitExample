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

using fruit::Component;
using fruit::Injector;
using fruit::createComponent;


#define NO_INJECT
#define REGISTER_THE_FACTORY

//#define ONLY_ONE_INJECT
#define DOUBLE
#define INT


#if !defined(NO_INJECT)

#if defined(ONLY_ONE_INJECT) && defined(DOUBLE)
#undef INT
#endif

#endif

class ScalerImpl : public Scaler
{
private:
  Multiplier* multiplier;
  double factor;

public:
#if defined(NO_INJECT)
    ScalerImpl(ASSISTED(double) factor, Multiplier* multiplier) : multiplier(multiplier), factor(factor) {}
    ScalerImpl(ASSISTED(int) factor, Multiplier* multiplier) : multiplier(multiplier), factor(factor) {}

#else

#if defined(ONLY_ONE_INJECT)

#if defined(DOUBLE)
  INJECT(ScalerImpl(ASSISTED(double) factor, Multiplier* multiplier)) : multiplier(multiplier), factor(factor) {}
#endif

#if defined(INT)
  INJECT(ScalerImpl(ASSISTED(int) factor, Multiplier* multiplier)) : multiplier(multiplier), factor(factor) {}
#endif

#else

    INJECT(ScalerImpl(ASSISTED(double) factor, Multiplier* multiplier)) : multiplier(multiplier), factor(factor) {}
    INJECT(ScalerImpl(ASSISTED(int) factor, Multiplier* multiplier)) : multiplier(multiplier), factor(factor) {}
#endif

#endif

  double scale(double x) override {
    return multiplier->multiply(x, factor);
  }
};


Component<ScalerFactory> getScalerComponent()
{
    return createComponent()
#if defined(REGISTER_THE_FACTORY)
                                .registerFactory< std::unique_ptr<ScalerImpl>(fruit::Assisted<double>,Multiplier*)>(
                                    [ ](double n, Multiplier* Multiplier) {
                                        return std::unique_ptr<ScalerImpl>(new ScalerImpl(n, Multiplier));
                                    })
                                .registerFactory< std::unique_ptr<ScalerImpl>(fruit::Assisted<int>,Multiplier*)>(
                                    [ ](int n, Multiplier* Multiplier) {
                                        return std::unique_ptr<ScalerImpl>(new ScalerImpl(n, Multiplier));
                                    })

#endif
                                .bind<Scaler, ScalerImpl>()
                                .install(getMultiplierComponent);
}
