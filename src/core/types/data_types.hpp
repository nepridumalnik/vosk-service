#pragma once

#include <vosk_api.h>

#include <memory>

/// @brief Уникальный указатель на модель
using ModelPtr = std::unique_ptr<VoskModel, decltype(&vosk_model_free)>;

/// @brief Уникальный указатель на распознавателя
using RecognizerPtr = std::unique_ptr<VoskRecognizer, decltype(&vosk_recognizer_free)>;
