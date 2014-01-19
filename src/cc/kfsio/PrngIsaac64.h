//---------------------------------------------------------- -*- Mode: C++ -*-
// $Id$
//
// Created 2014/01/18
// Author: Mike Ovsiannikov
//
// Copyright 2014 Quantcast Corp.
//
// This file is part of Kosmos File System (KFS).
//
// Licensed under the Apache License, Version 2.0
// (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied. See the License for the specific language governing
// permissions and limitations under the License.
//
// \brief isaac64 pseudo random number generator interface.
//
//----------------------------------------------------------------------------

#ifndef PRNG_ISAAC64_H
#define PRNG_ISAAC64_H

#include <inttypes.h>

namespace KFS
{

class PrngIsaac64
{
public:
    PrngIsaac64();
    ~PrngIsaac64();
    bool Init();
    uint64_t Rand()
    {
        if (mPtr == mEndPtr) {
            Isaac64();
        }
        return *mPtr++;
    }
private:
    class Impl;
    Impl&                 mImpl;
    const uint64_t* const mEndPtr;
    const uint64_t*       mPtr;

    void Isaac64();
private:
    PrngIsaac64(
        const PrngIsaac64& inPrng);
    PrngIsaac64& operator=(
        const PrngIsaac64& inPrng);
};

} // namespace KFS

#endif /* PRNG_ISAAC64_H */