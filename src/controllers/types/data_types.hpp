#pragma once

#include <string>

namespace controllers
{

/// @brief Описание языковой модели
struct LanguageModel
{
    /// @brief Имя языковой модели
    std::string name;

    /// @brief Язык
    std::string language;

    /// @brief Путь до каталога с языковой моделью
    std::string path;

    /// @brief Описание
    std::string description;
};

} // namespace controllers
