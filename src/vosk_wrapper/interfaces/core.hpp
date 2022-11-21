#pragma once

#include <vosk_wrapper/interfaces/model.hpp>

#include <memory>
#include <string>

namespace vosk_wrapper
{

struct Core
{
    /// @brief Получить языковую модель
    /// @param [in] modelName Название модели
    /// @return Слушатель от модели или nullptr, если такой модели не существует
    virtual std::unique_ptr<Listener> GetListener(const std::string &modelName) = 0;

    /// @brief Добавить языковую модель
    /// @param [in] path Путь до файлов обученной модели
    /// @param [in] name Название модели
    virtual void AddModel(const std::string &path, const std::string &name) = 0;

    /// @brief Удалить языковую модель
    /// @param [in] name Название модели
    virtual void RemoveModel(const std::string &name) = 0;

    /// @brief Деструктор
    virtual ~Core() = default;
};

} // namespace vosk_wrapper
