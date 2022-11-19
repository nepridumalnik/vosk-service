#include <impl/core_impl.hpp>
#include <impl/model_impl.hpp>

#include <iostream>

namespace vosk_server
{
namespace core
{

std::unique_ptr<Listener> CoreImpl::GetListener(const std::string &modelName)
{
    auto model = models_.find(modelName);

    if (models_.end() == model)
    {
        return {};
    }

    return model->second->GetRecognizer();
}

void CoreImpl::AddModel(const std::string &path, const std::string &name)
try
{
    {
        const auto model = models_.find(name);

        if (models_.end() != model)
        {
            return;
        }
    }

    std::unique_ptr<Model> model = std::make_unique<ModelImpl>(path);
    models_.insert({name, std::move(model)});
}
catch (const std::exception &e)
{
    std::cerr << e.what() << std::endl;
}

void CoreImpl::RemoveModel(const std::string &name)
{
    const auto model = models_.find(name);

    if (models_.end() == model)
    {
        return;
    }

    models_.erase(model);
}

} // namespace core
} // namespace vosk_server
