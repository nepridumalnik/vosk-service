#pragma once

#include <vosk_wrapper/core/interfaces/listener.hpp>

#include <memory>

namespace vosk_wrapper
{
namespace core
{

struct Model
{
    /// @brief Получить распознаватель текста
    /// @return Распознаватель
    virtual std::unique_ptr<Listener> GetRecognizer() = 0;

    /// @brief Деструктор
    virtual ~Model() = default;
};

} // namespace core
} // namespace vosk_wrapper
