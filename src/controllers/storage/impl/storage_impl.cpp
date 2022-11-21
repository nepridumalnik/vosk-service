#include <controllers/storage/impl/storage_impl.hpp>

namespace controllers
{

namespace storage
{

std::vector<LanguageModel> StorageImpl::GetModels()
{
    return {};
}

void StorageImpl::AddModel(const LanguageModel &model)
{
}

void StorageImpl::RemoveModel(const std::string &modelName)
{
}

} // namespace storage

} // namespace controllers
