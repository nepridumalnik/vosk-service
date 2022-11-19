#pragma once

#include <string>

namespace vosk_wrapper
{
namespace core
{

struct Listener
{
    /// @brief Распознать звук
    /// @param [in] audio Аудиодорожка в формате WAV
    /// @return Распознанный текст или пустую строку, если не удалось распознать
    virtual std::string Recognize(const std::string &audio) = 0;

    /// @brief Деструктор
    virtual ~Listener() = default;
};

} // namespace core
} // namespace vosk_wrapper
