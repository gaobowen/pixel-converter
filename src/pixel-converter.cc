#include "pixel-converter.h"

Napi::Value BGRA2RGBA(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    if (info.Length() < 1)
        return Napi::Boolean::New(env, false);
    if (!info[0].IsBuffer() && !info[0].IsArrayBuffer())
        return Napi::Boolean::New(env, false);
    bool isBuffer = info[0].IsBuffer();
    unsigned char *_data = nullptr;
    size_t len = 0;
    if (isBuffer)
    {
        auto buff = info[0].As<Napi::Buffer<unsigned char>>();
        len = buff.ByteLength();
        _data = buff.Data();
    }
    else
    {
        auto arrbuff = info[0].As<Napi::ArrayBuffer>();
        len = arrbuff.ByteLength();
        _data = (unsigned char *)arrbuff.Data();
    }
    if (len % 4 > 0)
    {
        return Napi::Boolean::New(env, false);
    }
    unsigned char temp = 0;
    for (size_t i = 0; i < len; i += 4)
    {
        temp = *(_data + i);
        *(_data + i) = *(_data + i + 2);
        *(_data + i + 2) = temp;
    }

    return Napi::Boolean::New(env, true);
}