#include <iostream>
#include "streebog.h"

std::string hex_representation(const char * data, size_t length)
{
    std::string result;
    for (size_t i = 0; i < length; ++i)
    {
        unsigned char byte = *reinterpret_cast<const unsigned char*>(&data[i]);
        unsigned char first_part = byte >> 4;
        unsigned char secnd_part = byte & ((1 << 4) - 1);
        std::string byte_repr = "0x";
        byte_repr += (first_part < 10 ? '0' + char(first_part) : 'a' + char(first_part) - 10);
        byte_repr += (secnd_part < 10 ? '0' + char(secnd_part) : 'a' + char(secnd_part) - 10);

        result += byte_repr;

        if (i < length - 1)
            result += ' ';
    }
    return result;
}

int main()
{
    std::unique_ptr<cppcrypto::streebog> hash = std::make_unique<cppcrypto::streebog>(512);
    hash->init();
    unsigned char res[64];
    hash->hash_string("", res);

    std::cout << "Empty string hash result:" << std::endl;
    std::cout << hex_representation(reinterpret_cast<char*>(res), 64) << std::endl;

    const std::string test_case
        = "The quick brown fox jumps over the lazy dog.";
    hash->clear();
    hash->hash_string(test_case, res);
    std::cout << "Hash for case: " << test_case << std::endl;
    std::cout << hex_representation(reinterpret_cast<char*>(res), 64);
    return 0;
}
