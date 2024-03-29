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

#ifndef SCALER_H
#define SCALER_H

#include <fruit/fruit.h>

class Scaler {
public:
  virtual double scale(double x) = 0;

  virtual ~Scaler() = default;
};

using ScalerFactory = std::function<std::unique_ptr<Scaler>(double)>;

using ScalerFactory2 = std::function<std::unique_ptr<Scaler>(int)>;

//fruit::Component<ScalerFactory> getScalerComponent();

fruit::Component<ScalerFactory, ScalerFactory2> getScalerComponent();

#endif // SCALER_H
