#pragma once

#include <vosk_wrapper/interfaces/listener.hpp>

#include <memory>

namespace vosk_wrapper
{

struct Model
{
    /// @brief Получить распознаватель текста
    /// @return Распознаватель
    virtual std::unique_ptr<Listener> GetRecognizer() = 0;

    /// @brief Деструктор
    virtual ~Model() = default;
};

} // namespace vosk_wrapper
