#pragma once

#include <string>

namespace vosk_server
{
namespace core
{

struct Listener
{
    /// @brief Распознать звук
    /// @param [in] audio Аудиодорожка в формате WAV
    /// @return Распознанный текст
    virtual std::string operator<<(const std::string &audio) = 0;
};

} // namespace core
} // namespace vosk_server
