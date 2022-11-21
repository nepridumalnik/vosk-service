#pragma once

#include <controllers/interfaces/storage.hpp>

#include <soci/soci.h>

namespace controllers
{

namespace storage
{

class StorageImpl : public Storage
{
public:
    /// @brief see Storage
    std::vector<LanguageModel> GetModels() override;

    /// @brief see Storage
    void AddModel(const LanguageModel &model) override;

    /// @brief see Storage
    void RemoveModel(const std::string &modelName) override;

private:
    soci::session session_;
};

} // namespace storage

} // namespace controllers
