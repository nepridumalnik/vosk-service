#pragma once

#include <controllers/types/data_types.hpp>

#include <string>
#include <vector>

namespace controllers
{

class Storage
{
    /// @brief Получить список всех языковых моделей
    /// @return Список моделей
    virtual std::vector<LanguageModel> GetModels() = 0;

    /// @brief Добавить языковую модель
    /// @param model Языковая модель
    virtual void AddModel(const LanguageModel &model) = 0;

    /// @brief Удалить языковую модель
    /// @param modelName Имя языковой модели
    virtual void RemoveModel(const std::string &modelName) = 0;
};

} // namespace controllers
