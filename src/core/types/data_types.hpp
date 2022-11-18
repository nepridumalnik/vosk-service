#pragma once

#include <vosk_api.h>

#include <memory>

using ModelPtr = std::unique_ptr<VoskModel, decltype(&vosk_model_free)>;
using RecognizerPtr = std::unique_ptr<VoskRecognizer, decltype(&vosk_recognizer_free)>;
