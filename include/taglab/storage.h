#pragma once

#include <ranges>

template <class StorageType>
concept Storage = requires(StorageType storage, StorageType const storageConst)
{
    { storage.addEntries(std::ranges::empty_view<int>{}) } -> std::same_as<void>;
};
