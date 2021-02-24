#include <napi.h>
#include "pixel-converter.h"

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "BGRA2RGBA"), Napi::Function::New(env, BGRA2RGBA));
    return exports;
}

NODE_API_MODULE(pixel_converter, Init)