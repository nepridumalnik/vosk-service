#include <vosk_wrapper/core/impl/listener_impl.hpp>
#include <vosk_wrapper/core/impl/model_impl.hpp>

#include <stdexcept>

constexpr float BitRate = 44000.0f;

namespace vosk_wrapper
{
namespace core
{

ModelImpl::ModelImpl(const std::string &path) : model_{nullptr, &vosk_model_free}
{
    model_ = ModelPtr{vosk_model_new(path.c_str()), &vosk_model_free};

    if (!model_)
    {
        throw std::runtime_error{"Failed to create model with path: " + path};
    }
}

std::unique_ptr<Listener> ModelImpl::GetRecognizer()
{
    auto recognizer = RecognizerPtr{vosk_recognizer_new(model_.get(), BitRate), &vosk_recognizer_free};
    return std::make_unique<ListenerImpl>(std::move(recognizer), model_);
}

} // namespace core

} // namespace vosk_wrapper
