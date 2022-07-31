// Copyright (c) 2014-2021 The Gridcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or https://opensource.org/licenses/mit-license.php.

#ifndef GRIDCOIN_SUPPORT_FILEHASH_H
#define GRIDCOIN_SUPPORT_FILEHASH_H

#include "serialize.h"
#include "streams.h"
#include "hash.h"

namespace GRC {
class CAutoHasherFile : public CAutoFile, public CHashWriter
{
public:
    explicit CAutoHasherFile(FILE* filenew, int nTypeIn, int nVersionIn) :
        CAutoFile(filenew, nTypeIn, nVersionIn),
        CHashWriter(nTypeIn, nVersionIn) {};


    void read(Span<std::byte> dst)
    {
        CAutoFile::read(dst);
        CHashWriter::write(dst);
    }

    void write(Span<const std::byte> src)
    {
        CAutoFile::write(src);
        CHashWriter::write(src);
    }

    int GetType() const { return CAutoFile::GetType(); }
    int GetVersion() const { return CAutoFile::GetVersion(); }

    template <typename T>
    CAutoHasherFile& operator<<(const T& obj)
    {
        ::Serialize(*this, obj);
        return *this;
    }

    template <typename T>
    CAutoHasherFile& operator>>(T& obj)
    {
        ::Unserialize(*this, obj);
        return *this;
    }
};
} // namespace GRC

#endif // GRIDCOIN_SUPPORT_FILEHASH_H
