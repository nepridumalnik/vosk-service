#include <vosk_wrapper/core/impl/listener_impl.hpp>

namespace vosk_wrapper
{
namespace core
{

ListenerImpl::ListenerImpl(RecognizerPtr recognizer, ModelPtr model) : recognizer_{std::move(recognizer)}, model_{model}
{
}

std::string ListenerImpl::Recognize(const std::string &audio)
{
    // TODO:
    // Обрабатывать пустые и неполные дорожки
    auto res = vosk_recognizer_accept_waveform(recognizer_.get(), audio.c_str(), audio.size());

    if (0 != res)
    {
        return {};
    }

    std::string result = vosk_recognizer_final_result(recognizer_.get());

    return std::move(result);
}

ListenerImpl::~ListenerImpl()
{
    recognizer_.reset();
    model_.reset();
}

} // namespace core

} // namespace vosk_wrapper
