#include <vosk_wrapper/core/impl/core_impl.hpp>
#include <vosk_wrapper/core/impl/model_impl.hpp>

#include <iostream>

namespace vosk_wrapper
{
namespace core
{

std::unique_ptr<Listener> CoreImpl::GetListener(const std::string &modelName)
{
    std::lock_guard<std::mutex> lock{mutex_};
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
    std::lock_guard<std::mutex> lock{mutex_};

    {
        const auto model = models_.find(name);

        if (models_.end() != model)
        {
            return;
        }
    }

    std::shared_ptr<Model> model = std::make_shared<ModelImpl>(path);
    models_.insert({name, std::move(model)});
}
catch (const std::exception &e)
{
    std::cerr << e.what() << std::endl;
}

void CoreImpl::RemoveModel(const std::string &name)
{
    std::lock_guard<std::mutex> lock{mutex_};
    const auto model = models_.find(name);

    if (models_.end() == model)
    {
        return;
    }

    models_.erase(model);
}

} // namespace core

} // namespace vosk_wrapper
