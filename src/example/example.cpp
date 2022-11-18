#include <vosk_api.h>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>

// https://github.com/alphacep/vosk-api/blob/master/c/test_vosk.c

static constexpr char ModelPath[] = "D:/Programming/C++/vosk-api/models/vosk-model-ru-0.22";
static constexpr char Voice[] = "D:/Programming/C++/vosk-api/resources/novy_god.wav";

int main(int argc, char const *argv[])
{
    using ModelPtr = std::unique_ptr<VoskModel, decltype(&vosk_model_free)>;
    using RecognizerPtr = std::unique_ptr<VoskRecognizer, decltype(&vosk_recognizer_free)>;

    ModelPtr model{nullptr, &vosk_model_free};
    RecognizerPtr recognizer{nullptr, &vosk_recognizer_free};

    model = ModelPtr{vosk_model_new(ModelPath), &vosk_model_free};
    recognizer = RecognizerPtr{vosk_recognizer_new(model.get(), 44000.0), &vosk_recognizer_free};

    std::string buffer;
    std::string result;

    std::ifstream in{Voice, std::ios::binary};
    in.seekg(0, std::ios::end);
    buffer.resize(in.tellg());
    in.seekg(44, std::ios::beg);
    in.read(&buffer[0], buffer.size());
    in.close();

    int res = vosk_recognizer_accept_waveform(recognizer.get(), buffer.c_str(), buffer.size());
    result += vosk_recognizer_final_result(recognizer.get());

    std::ofstream out{"output.txt"};
    out << result;

    return 0;
}
