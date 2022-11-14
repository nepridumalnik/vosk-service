#pragma once

#include <string>

struct Recognizer
{
    /// @brief Распознать звук
    /// @param [in] audio Аудиодорожка в формате WAV
    /// @return Распознанный текст
    virtual std::string Recognize(const std::string &audio) = 0;
};
