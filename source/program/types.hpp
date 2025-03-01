#pragma once

namespace sead
{
    struct SafeString
    {
        char *string;
        size_t bufCapacity;
        size_t length;
    };

    struct BufferedSafeString
    {
        SafeString mString;
        int mBufferSize;
    };

    template <size_t N>
    struct FixedSafeString
    {
        char *mString;
        int mSize = N;
        char mStringStorage[N];
    };
}

struct ArmorSortInfo
{
    int index;
    sead::FixedSafeString<256> name;
    sead::FixedSafeString<64> category;
    sead::FixedSafeString<64> series;
    u32 color_variation;
};

struct ListNode
{
    void *mpPrev;
    void *mpNext;
};

struct SortInfo
{
    int mIndex;
    ListNode mListNode;
};