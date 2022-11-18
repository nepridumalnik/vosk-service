#include <impl/listener_impl.hpp>

namespace vosk_server
{
namespace core
{

ListenerImpl::ListenerImpl(RecognizerPtr recognizer) : recognizer_{std::move(recognizer)}
{
}

std::string ListenerImpl::operator<<(const std::string &audio)
{
    auto res = vosk_recognizer_accept_waveform(recognizer_.get(), audio.c_str(), audio.size());

    if (0 != res)
    {
        return {};
    }

    std::string result = vosk_recognizer_final_result(recognizer_.get());

    return std::move(result);
}

} // namespace core
} // namespace vosk_server
