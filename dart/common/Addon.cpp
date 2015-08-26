/*
 * Copyright (c) 2015, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s): Michael X. Grey <mxgrey@gatech.edu>
 *
 * Georgia Tech Graphics Lab and Humanoid Robotics Lab
 *
 * Directed by Prof. C. Karen Liu and Prof. Mike Stilman
 * <karenliu@cc.gatech.edu> <mstilman@cc.gatech.edu>
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#include <cassert>
#include <string>
#include <iostream>

#include "dart/common/Addon.h"
#include "dart/common/Console.h"

namespace dart {
namespace common {

//==============================================================================
void Addon::setState(const std::unique_ptr<State>& /*otherState*/)
{
  // Do nothing
}

//==============================================================================
const Addon::State* Addon::getState() const
{
  return mStatePtr;
}

//==============================================================================
void Addon::setProperties(const std::unique_ptr<Properties>& /*someProperties*/)
{
  // Do nothing
}

//==============================================================================
const Addon::Properties* Addon::getProperties() const
{
  return mPropertiesPtr;
}

//==============================================================================
const std::string& Addon::getType() const
{
  return mType;
}

//==============================================================================
Addon::Addon(AddonManager* manager, const std::string& type)
  : mType(type)
{
  if(nullptr == manager)
  {
    dterr << "[Addon::constructor] You are not allowed to construct an Addon "
          << "outside of an AddonManager!\n";
    assert(false);
  }

  setStatePtr();
  setPropertiesPtr();
}

//==============================================================================
void Addon::setStatePtr(State* ptr)
{
  mStatePtr = ptr;
}

//==============================================================================
void Addon::setPropertiesPtr(Properties* ptr)
{
  mPropertiesPtr = ptr;
}

//==============================================================================
void Addon::changeManager(AddonManager* newManager)
{
  // Do nothing
}


} // namespace common
} // namespace dart
