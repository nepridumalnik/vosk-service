#include <vosk_api.h>

#include <iostream>
#include <fstream>
#include <cstdio>

// https://github.com/alphacep/vosk-api/blob/master/c/test_vosk.c

static constexpr char ModelPath[] = "D:/Programming/C++/vosk-api/models/vosk-model-ru-0.22";
static constexpr char Voice[] = "D:/Programming/C++/vosk-api/resources/novy_god.wav";

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Russian");

    FILE *wavInput{};
    char buf[3200];
    int nread{};
    int final{};

    std::string result;

    VoskModel *model{};
    VoskRecognizer *recognizer{};
    VoskRecognizer *recognizer2{};

    model = vosk_model_new(ModelPath);
    recognizer = vosk_recognizer_new(model, 44000.0);

    {
        std::string buffer;
        std::string result2;
        recognizer2 = vosk_recognizer_new(model, 44000.0);

        std::ifstream in{Voice, std::ios::binary};
        in.seekg(0, std::ios::end);
        buffer.resize(in.tellg());
        in.seekg(44, std::ios::beg);
        in.read(&buffer[0], buffer.size());
        in.close();

        int res = vosk_recognizer_accept_waveform(recognizer2, buffer.c_str(), buffer.size());
        result2 += vosk_recognizer_final_result(recognizer2);
        vosk_recognizer_free(recognizer2);

        std::ofstream of2{"output2.txt"};
        of2 << result2;
    }

    wavInput = fopen(Voice, "rb");
    fseek(wavInput, 44, SEEK_SET);

    while (!feof(wavInput))
    {
        nread = fread(buf, 1, sizeof(buf), wavInput);
        final = vosk_recognizer_accept_waveform(recognizer, buf, nread);

        if (final)
        {
            result += vosk_recognizer_result(recognizer);
        }
        else
        {
            result += vosk_recognizer_partial_result(recognizer);
        }
    }

    fclose(wavInput);

    result += vosk_recognizer_final_result(recognizer);

    std::cout << result << std::endl;

    std::ofstream of{"output.txt"};
    of << result;

    vosk_recognizer_free(recognizer);
    vosk_model_free(model);

    return 0;
}
