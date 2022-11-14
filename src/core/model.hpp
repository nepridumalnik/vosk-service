#pragma once

#include <recognizer.hpp>

#include <memory>

struct Model
{
    /// @brief Получить распознаватель текста
    /// @return Распознаватель
    virtual std::unique_ptr<Recognizer> GetRecognizer() = 0;
};
