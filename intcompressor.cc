#include <iostream>
#include <napi.h>
#include "compression/bitpack.h"
#include "compression/eliasfano.h"
#include "compression/vint.h"
#include "compression/vp4.h"
#include "compression/vsimple.h"


Napi::Value VbZEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *op = vbzenc32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t len = op - dst.Data();

  return Napi::Number::New(env, len);
}

Napi::Value VbZDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = vbzdec32(src.Data(), len, dst.Data(), 0);
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value VbEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *op = vbenc32(src.Data(), src.ElementLength(), dst.Data());
  ptrdiff_t encoded = op - dst.Data();

  return Napi::Number::New(env, encoded);
}

Napi::Value VbDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = vbdec32(src.Data(), len, dst.Data());
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value VbDEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *op = vbdenc32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t len = op - dst.Data();

  return Napi::Number::New(env, len);
}

Napi::Value VbDDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = vbddec32(src.Data(), len, dst.Data(), 0);
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value VbD1Encode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *op = vbd1enc32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t len = op - dst.Data();

  return Napi::Number::New(env, len);
}

Napi::Value VbD1Decode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = vbd1dec32(src.Data(), len, dst.Data(), 0);
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value VbXEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *op = vbxenc32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t len = op - dst.Data();

  return Napi::Number::New(env, len);
}

Napi::Value VbXDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = vbxdec32(src.Data(), len, dst.Data(), 0);
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value VbDdEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *op = vbddenc32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t len = op - dst.Data();

  return Napi::Number::New(env, len);
}

Napi::Value VbDdDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = vbdddec32(src.Data(), len, dst.Data(), 0);
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value V8Encode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *op = v8enc32(src.Data(), src.ElementLength(), dst.Data());
  ptrdiff_t len = op - dst.Data();

  return Napi::Number::New(env, len);
}

Napi::Value V8Decode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = v8dec32(src.Data(), len, dst.Data());
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value V8DEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *op = v8denc32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t len = op - dst.Data();

  return Napi::Number::New(env, len);
}

Napi::Value V8DDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = v8ddec32(src.Data(), len, dst.Data(), 0);
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value V8D1Encode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *op = v8d1enc32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t len = op - dst.Data();

  return Napi::Number::New(env, len);
}

Napi::Value V8D1Decode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = v8d1dec32(src.Data(), len, dst.Data(), 0);
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value V8ZEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *op = v8zenc32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t len = op - dst.Data();

  return Napi::Number::New(env, len);
}

Napi::Value V8ZDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = v8zdec32(src.Data(), len, dst.Data(), 0);
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value V8XEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *op = v8xenc32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t len = op - dst.Data();

  return Napi::Number::New(env, len);
}

Napi::Value V8XDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = v8xdec32(src.Data(), len, dst.Data(), 0);
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value V8NEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t len = v8nenc32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, len);
}

Napi::Value V8NDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = v8ndec32(src.Data(), len.Uint32Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value V8NDEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t len = v8ndenc32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, len);
}

Napi::Value V8NDDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = v8nddec32(src.Data(), len.Uint32Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value V8ND1Encode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t len = v8nd1enc32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, len);
}

Napi::Value V8ND1Decode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = v8nd1dec32(src.Data(), len.Uint32Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value V8NZEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t len = v8nzenc32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, len);
}

Napi::Value V8NZDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = v8nzdec32(src.Data(), len.Uint32Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value V8NEncode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t len = v8nenc128v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, len);
}

Napi::Value V8NDecode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = v8ndec128v32(src.Data(), len.Uint32Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value V8NDEncode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t len = v8ndenc128v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, len);
}

Napi::Value V8NDDecode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = v8nddec128v32(src.Data(), len.Uint32Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value V8ND1Encode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t len = v8nd1enc128v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, len);
}

Napi::Value V8ND1Decode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = v8nd1dec128v32(src.Data(), len.Uint32Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value V8NZEncode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t len = v8nzenc128v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, len);
}

Napi::Value V8NZDecode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = v8nzdec128v32(src.Data(), len.Uint32Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value V8NEncode256v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t len = v8nenc256v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, len);
}

Napi::Value V8NDecode256v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = v8ndec256v32(src.Data(), len.Uint32Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value V8NDEncode256v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t len = v8ndenc256v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, len);
}

Napi::Value V8NDDecode256v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = v8nddec256v32(src.Data(), len.Uint32Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value V8ND1Encode256v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t len = v8nd1enc256v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, len);
}

Napi::Value V8ND1Decode256v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = v8nd1dec256v32(src.Data(), len.Uint32Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value V8NZEncode256v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t len = v8nzenc256v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, len);
}

Napi::Value V8NZDecode256v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = v8nzdec256v32(src.Data(), len.Uint32Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

////////// vsimple
Napi::Value VsEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *p = vsenc32(src.Data(), src.ElementLength(), dst.Data());
  ptrdiff_t encoded = p - dst.Data();

  return Napi::Number::New(env, encoded);
}

Napi::Value VsDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = vsdec32(src.Data(), len.Uint32Value(), dst.Data());
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value VsEncode16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *p = vsenc16(src.Data(), src.ElementLength(), dst.Data());
  ptrdiff_t encoded = p - dst.Data();

  return Napi::Number::New(env, encoded);
}

Napi::Value VsDecode16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = vsdec16(src.Data(), len.Uint32Value(), dst.Data());
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value VsEncode8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *p = vsenc8(src.Data(), src.ElementLength(), dst.Data());
  ptrdiff_t encoded = p - dst.Data();

  return Napi::Number::New(env, encoded);
}

Napi::Value VsDecode8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint8Array dst = info[2].As<Napi::Uint8Array>();

  if (len.Uint32Value() < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *op = vsdec8(src.Data(), len.Uint32Value(), dst.Data());
  ptrdiff_t decoded = op - src.Data();

  return Napi::Number::New(env, decoded);
}

/////// vp4 (TurboPFor)
Napi::Value P4NEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nenc32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4ndec32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NEncode16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nenc16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NDecode16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4ndec16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NEncode8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nenc8(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NDecode8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint8Array dst = info[2].As<Napi::Uint8Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4ndec8(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NEncode128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nenc128v16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NDecode128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4ndec128v16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NEncode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nenc128v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NDecode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4ndec128v32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NDEncode8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4ndenc8(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NDDecode8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint8Array dst = info[2].As<Napi::Uint8Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nddec8(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NDEncode16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4ndenc16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NDDecode16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nddec16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NDEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4ndenc32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NDDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nddec32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NDEncode128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4ndenc128v16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NDDecode128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nddec128v16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NDEncode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4ndenc128v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NDDecode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nddec128v32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4ND1Encode8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nd1enc8(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4ND1Decode8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint8Array dst = info[2].As<Napi::Uint8Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nd1dec8(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4ND1Encode16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nd1enc16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4ND1Decode16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nd1dec16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4ND1Encode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nd1enc32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4ND1Decode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nd1dec32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4ND1Encode128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nd1enc128v16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4ND1Decode128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nd1dec128v16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4ND1Encode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nd1enc128v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4ND1Decode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nd1dec128v32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NZEncode8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nzenc8(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NZDecode8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint8Array dst = info[2].As<Napi::Uint8Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nzdec8(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NZEncode16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nzenc16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NZDecode16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nzdec16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NZEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nzenc32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NZDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nzdec32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NZEncode128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nzenc128v16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NZDecode128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nzdec128v16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value P4NZEncode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = p4nzenc128v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value P4NZDecode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = p4nzdec128v32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

/// binary packing
Napi::Value BitNPack32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnpack32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNUnpack32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnunpack32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNPack16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnpack16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNUnpack16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnunpack16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNPack8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnpack8(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNUnpack8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint8Array dst = info[2].As<Napi::Uint8Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnunpack8(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNPack128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnpack128v16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNUnpack128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnunpack128v16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNPack128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnpack128v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNUnpack128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnunpack128v32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNDPack8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitndpack8(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNDUnpack8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint8Array dst = info[2].As<Napi::Uint8Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitndunpack8(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNDPack16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitndpack16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNDUnpack16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitndunpack16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNDPack32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitndpack32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNDUnpack32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitndunpack32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNDPack128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitndpack128v16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNDUnpack128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitndunpack128v16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNDPack128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitndpack128v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNDUnpack128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitndunpack128v32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitND1Pack8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnd1pack8(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitND1Unpack8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint8Array dst = info[2].As<Napi::Uint8Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnd1unpack8(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitND1Pack16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnd1pack16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitND1Unpack16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnd1unpack16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitND1Pack32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnd1pack32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitND1Unpack32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnd1unpack32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitND1Pack128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnd1pack128v16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitND1Unpack128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnd1unpack128v16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitND1Pack128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnd1pack128v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitND1Unpack128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnd1unpack128v32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNZPack8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnzpack8(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNZUnpack8(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint8Array dst = info[2].As<Napi::Uint8Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnzunpack8(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNZPack16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnzpack16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNZUnpack16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnzunpack16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNZPack32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnzpack32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNZUnpack32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnzunpack32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNZPack128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint16Array src = info[0].As<Napi::Uint16Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnzpack128v16(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNZUnpack128v16(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint16Array dst = info[2].As<Napi::Uint16Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnzunpack128v16(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

Napi::Value BitNZPack128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  size_t encoded = bitnzpack128v32(src.Data(), src.ElementLength(), dst.Data());

  return Napi::Number::New(env, encoded);
}

Napi::Value BitNZUnpack128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  size_t decoded = bitnzunpack128v32(src.Data(), len.Int64Value(), dst.Data());

  return Napi::Number::New(env, decoded);
}

/// Elias Fano
Napi::Value EFanoEncode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *p = efanoenc32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t encoded = p - dst.Data();

  return Napi::Number::New(env, encoded);
}

Napi::Value EFanoDecode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *p = efanodec32(src.Data(), len.Int64Value(), dst.Data(), 0);
  ptrdiff_t decoded = p - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value EFano1Encode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *p = efano1enc32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t encoded = p - dst.Data();

  return Napi::Number::New(env, encoded);
}

Napi::Value EFano1Decode32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *p = efano1dec32(src.Data(), len.Int64Value(), dst.Data(), 0);
  ptrdiff_t decoded = p - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value EFanoEncode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *p = efanoenc128v32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t encoded = p - dst.Data();

  return Napi::Number::New(env, encoded);
}

Napi::Value EFanoDecode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *p = efanodec128v32(src.Data(), len.Int64Value(), dst.Data(), 0);
  ptrdiff_t decoded = p - src.Data();

  return Napi::Number::New(env, decoded);
}

Napi::Value EFano1Encode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint32Array src = info[0].As<Napi::Uint32Array>();
  Napi::Uint8Array dst = info[1].As<Napi::Uint8Array>();

  unsigned char *p = efano1enc128v32(src.Data(), src.ElementLength(), dst.Data(), 0);
  ptrdiff_t encoded = p - dst.Data();

  return Napi::Number::New(env, encoded);
}

Napi::Value EFano1Decode128v32(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the first argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong type of the second argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[2].IsTypedArray()) {
    Napi::TypeError::New(env, "Wrong type of the third argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Uint8Array src = info[0].As<Napi::Uint8Array>();
  Napi::Number len = info[1].ToNumber();
  Napi::Uint32Array dst = info[2].As<Napi::Uint32Array>();

  if (static_cast<size_t>(len.Int64Value()) < dst.ElementLength()) {
    Napi::TypeError::New(env, "Output array length is less than number of elements").ThrowAsJavaScriptException();
    return env.Null();
  }

  unsigned char *p = efano1dec128v32(src.Data(), len.Int64Value(), dst.Data(), 0);
  ptrdiff_t decoded = p - src.Data();

  return Napi::Number::New(env, decoded);
}

/////

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  // variable byte
  exports.Set(Napi::String::New(env, "VbEncode32"), Napi::Function::New(env, VbEncode32));
  exports.Set(Napi::String::New(env, "VbDecode32"), Napi::Function::New(env, VbDecode32));
  exports.Set(Napi::String::New(env, "VbDEncode32"), Napi::Function::New(env, VbDEncode32));
  exports.Set(Napi::String::New(env, "VbDDecode32"), Napi::Function::New(env, VbDDecode32));
  exports.Set(Napi::String::New(env, "VbD1Encode32"), Napi::Function::New(env, VbD1Encode32));
  exports.Set(Napi::String::New(env, "VbD1Decode32"), Napi::Function::New(env, VbD1Decode32));
  exports.Set(Napi::String::New(env, "VbZEncode32"), Napi::Function::New(env, VbZEncode32));
  exports.Set(Napi::String::New(env, "VbZDecode32"), Napi::Function::New(env, VbZDecode32));
  exports.Set(Napi::String::New(env, "VbXEncode32"), Napi::Function::New(env, VbXEncode32));
  exports.Set(Napi::String::New(env, "VbXDecode32"), Napi::Function::New(env, VbXDecode32));
  exports.Set(Napi::String::New(env, "VbDdEncode32"), Napi::Function::New(env, VbDdEncode32));
  exports.Set(Napi::String::New(env, "VbDdDecode32"), Napi::Function::New(env, VbDdDecode32));

  // turbo byte
  exports.Set(Napi::String::New(env, "V8Encode32"), Napi::Function::New(env, V8Encode32));
  exports.Set(Napi::String::New(env, "V8Decode32"), Napi::Function::New(env, V8Decode32));
  exports.Set(Napi::String::New(env, "V8DEncode32"), Napi::Function::New(env, V8DEncode32));
  exports.Set(Napi::String::New(env, "V8DDecode32"), Napi::Function::New(env, V8DDecode32));
  exports.Set(Napi::String::New(env, "V8D1Encode32"), Napi::Function::New(env, V8D1Encode32));
  exports.Set(Napi::String::New(env, "V8D1Decode32"), Napi::Function::New(env, V8D1Decode32));
  exports.Set(Napi::String::New(env, "V8ZEncode32"), Napi::Function::New(env, V8ZEncode32));
  exports.Set(Napi::String::New(env, "V8ZDecode32"), Napi::Function::New(env, V8ZDecode32));
  exports.Set(Napi::String::New(env, "V8XEncode32"), Napi::Function::New(env, V8XEncode32));
  exports.Set(Napi::String::New(env, "V8XDecode32"), Napi::Function::New(env, V8XDecode32));
  exports.Set(Napi::String::New(env, "V8NEncode32"), Napi::Function::New(env, V8NEncode32));
  exports.Set(Napi::String::New(env, "V8NDecode32"), Napi::Function::New(env, V8NDecode32));
  exports.Set(Napi::String::New(env, "V8NDEncode32"), Napi::Function::New(env, V8NDEncode32));
  exports.Set(Napi::String::New(env, "V8NDDecode32"), Napi::Function::New(env, V8NDDecode32));
  exports.Set(Napi::String::New(env, "V8ND1Encode32"), Napi::Function::New(env, V8ND1Encode32));
  exports.Set(Napi::String::New(env, "V8ND1Decode32"), Napi::Function::New(env, V8ND1Decode32));
  exports.Set(Napi::String::New(env, "V8NZEncode32"), Napi::Function::New(env, V8NZEncode32));
  exports.Set(Napi::String::New(env, "V8NZDecode32"), Napi::Function::New(env, V8NZDecode32));
  exports.Set(Napi::String::New(env, "V8NEncode128v32"), Napi::Function::New(env, V8NEncode128v32));
  exports.Set(Napi::String::New(env, "V8NDecode128v32"), Napi::Function::New(env, V8NDecode128v32));
  exports.Set(Napi::String::New(env, "V8NDEncode128v32"), Napi::Function::New(env, V8NDEncode128v32));
  exports.Set(Napi::String::New(env, "V8NDDecode128v32"), Napi::Function::New(env, V8NDDecode128v32));
  exports.Set(Napi::String::New(env, "V8ND1Encode128v32"), Napi::Function::New(env, V8ND1Encode128v32));
  exports.Set(Napi::String::New(env, "V8ND1Decode128v32"), Napi::Function::New(env, V8ND1Decode128v32));
  exports.Set(Napi::String::New(env, "V8NZEncode128v32"), Napi::Function::New(env, V8NZEncode128v32));
  exports.Set(Napi::String::New(env, "V8NZDecode128v32"), Napi::Function::New(env, V8NZDecode128v32));
  exports.Set(Napi::String::New(env, "V8NEncode256v32"), Napi::Function::New(env, V8NEncode256v32));
  exports.Set(Napi::String::New(env, "V8NDecode256v32"), Napi::Function::New(env, V8NDecode256v32));
  exports.Set(Napi::String::New(env, "V8NDEncode256v32"), Napi::Function::New(env, V8NDEncode256v32));
  exports.Set(Napi::String::New(env, "V8NDDecode256v32"), Napi::Function::New(env, V8NDDecode256v32));
  exports.Set(Napi::String::New(env, "V8ND1Encode256v32"), Napi::Function::New(env, V8ND1Encode256v32));
  exports.Set(Napi::String::New(env, "V8ND1Decode256v32"), Napi::Function::New(env, V8ND1Decode256v32));
  exports.Set(Napi::String::New(env, "V8NZEncode256v32"), Napi::Function::New(env, V8NZEncode256v32));
  exports.Set(Napi::String::New(env, "V8NZDecode256v32"), Napi::Function::New(env, V8NZDecode256v32));

  // vsimple
  exports.Set(Napi::String::New(env, "VsEncode32"), Napi::Function::New(env, VsEncode32));
  exports.Set(Napi::String::New(env, "VsDecode32"), Napi::Function::New(env, VsDecode32));
  exports.Set(Napi::String::New(env, "VsEncode16"), Napi::Function::New(env, VsEncode16));
  exports.Set(Napi::String::New(env, "VsDecode16"), Napi::Function::New(env, VsDecode16));
  exports.Set(Napi::String::New(env, "VsEncode8"), Napi::Function::New(env, VsEncode8));
  exports.Set(Napi::String::New(env, "VsDecode8"), Napi::Function::New(env, VsDecode8));

  // TurboPFor
  exports.Set(Napi::String::New(env, "P4NEncode32"), Napi::Function::New(env, P4NEncode32));
  exports.Set(Napi::String::New(env, "P4NDecode32"), Napi::Function::New(env, P4NDecode32));
  exports.Set(Napi::String::New(env, "P4NEncode16"), Napi::Function::New(env, P4NEncode16));
  exports.Set(Napi::String::New(env, "P4NDecode16"), Napi::Function::New(env, P4NDecode16));
  exports.Set(Napi::String::New(env, "P4NEncode8"), Napi::Function::New(env, P4NEncode8));
  exports.Set(Napi::String::New(env, "P4NDecode8"), Napi::Function::New(env, P4NDecode8));
  exports.Set(Napi::String::New(env, "P4NEncode128v32"), Napi::Function::New(env, P4NEncode128v32));
  exports.Set(Napi::String::New(env, "P4NDecode128v32"), Napi::Function::New(env, P4NDecode128v32));
  exports.Set(Napi::String::New(env, "P4NEncode128v16"), Napi::Function::New(env, P4NEncode128v16));
  exports.Set(Napi::String::New(env, "P4NDecode128v16"), Napi::Function::New(env, P4NDecode128v16));

  exports.Set(Napi::String::New(env, "P4NDEncode32"), Napi::Function::New(env, P4NDEncode32));
  exports.Set(Napi::String::New(env, "P4NDDecode32"), Napi::Function::New(env, P4NDDecode32));
  exports.Set(Napi::String::New(env, "P4NDEncode16"), Napi::Function::New(env, P4NDEncode16));
  exports.Set(Napi::String::New(env, "P4NDDecode16"), Napi::Function::New(env, P4NDDecode16));
  exports.Set(Napi::String::New(env, "P4NDEncode8"), Napi::Function::New(env, P4NDEncode8));
  exports.Set(Napi::String::New(env, "P4NDDecode8"), Napi::Function::New(env, P4NDDecode8));
  exports.Set(Napi::String::New(env, "P4NDEncode128v32"), Napi::Function::New(env, P4NDEncode128v32));
  exports.Set(Napi::String::New(env, "P4NDDecode128v32"), Napi::Function::New(env, P4NDDecode128v32));
  exports.Set(Napi::String::New(env, "P4NDEncode128v16"), Napi::Function::New(env, P4NDEncode128v16));
  exports.Set(Napi::String::New(env, "P4NDDecode128v16"), Napi::Function::New(env, P4NDDecode128v16));

  exports.Set(Napi::String::New(env, "P4ND1Encode32"), Napi::Function::New(env, P4ND1Encode32));
  exports.Set(Napi::String::New(env, "P4ND1Decode32"), Napi::Function::New(env, P4ND1Decode32));
  exports.Set(Napi::String::New(env, "P4ND1Encode16"), Napi::Function::New(env, P4ND1Encode16));
  exports.Set(Napi::String::New(env, "P4ND1Decode16"), Napi::Function::New(env, P4ND1Decode16));
  exports.Set(Napi::String::New(env, "P4ND1Encode8"), Napi::Function::New(env, P4ND1Encode8));
  exports.Set(Napi::String::New(env, "P4ND1Decode8"), Napi::Function::New(env, P4ND1Decode8));
  exports.Set(Napi::String::New(env, "P4ND1Encode128v32"), Napi::Function::New(env, P4ND1Encode128v32));
  exports.Set(Napi::String::New(env, "P4ND1Decode128v32"), Napi::Function::New(env, P4ND1Decode128v32));
  exports.Set(Napi::String::New(env, "P4ND1Encode128v16"), Napi::Function::New(env, P4ND1Encode128v16));
  exports.Set(Napi::String::New(env, "P4ND1Decode128v16"), Napi::Function::New(env, P4ND1Decode128v16));

  exports.Set(Napi::String::New(env, "P4NZEncode32"), Napi::Function::New(env, P4NZEncode32));
  exports.Set(Napi::String::New(env, "P4NZDecode32"), Napi::Function::New(env, P4NZDecode32));
  exports.Set(Napi::String::New(env, "P4NZEncode16"), Napi::Function::New(env, P4NZEncode16));
  exports.Set(Napi::String::New(env, "P4NZDecode16"), Napi::Function::New(env, P4NZDecode16));
  exports.Set(Napi::String::New(env, "P4NZEncode8"), Napi::Function::New(env, P4NZEncode8));
  exports.Set(Napi::String::New(env, "P4NZDecode8"), Napi::Function::New(env, P4NZDecode8));
  exports.Set(Napi::String::New(env, "P4NZEncode128v32"), Napi::Function::New(env, P4NZEncode128v32));
  exports.Set(Napi::String::New(env, "P4NZDecode128v32"), Napi::Function::New(env, P4NZDecode128v32));
  exports.Set(Napi::String::New(env, "P4NZEncode128v16"), Napi::Function::New(env, P4NZEncode128v16));
  exports.Set(Napi::String::New(env, "P4NZDecode128v16"), Napi::Function::New(env, P4NZDecode128v16));

  // bit packing
  exports.Set(Napi::String::New(env, "BitNPack32"), Napi::Function::New(env, BitNPack32));
  exports.Set(Napi::String::New(env, "BitNUnpack32"), Napi::Function::New(env, BitNUnpack32));
  exports.Set(Napi::String::New(env, "BitNPack16"), Napi::Function::New(env, BitNPack16));
  exports.Set(Napi::String::New(env, "BitNUnpack16"), Napi::Function::New(env, BitNUnpack16));
  exports.Set(Napi::String::New(env, "BitNPack8"), Napi::Function::New(env, BitNPack8));
  exports.Set(Napi::String::New(env, "BitNUnpack8"), Napi::Function::New(env, BitNUnpack8));
  exports.Set(Napi::String::New(env, "BitNPack128v32"), Napi::Function::New(env, BitNPack128v32));
  exports.Set(Napi::String::New(env, "BitNUnpack128v32"), Napi::Function::New(env, BitNUnpack128v32));
  exports.Set(Napi::String::New(env, "BitNPack128v16"), Napi::Function::New(env, BitNPack128v16));
  exports.Set(Napi::String::New(env, "BitNUnpack128v16"), Napi::Function::New(env, BitNUnpack128v16));

  exports.Set(Napi::String::New(env, "BitNDPack32"), Napi::Function::New(env, BitNDPack32));
  exports.Set(Napi::String::New(env, "BitNDUnpack32"), Napi::Function::New(env, BitNDUnpack32));
  exports.Set(Napi::String::New(env, "BitNDPack16"), Napi::Function::New(env, BitNDPack16));
  exports.Set(Napi::String::New(env, "BitNDUnpack16"), Napi::Function::New(env, BitNDUnpack16));
  exports.Set(Napi::String::New(env, "BitNDPack8"), Napi::Function::New(env, BitNDPack8));
  exports.Set(Napi::String::New(env, "BitNDUnpack8"), Napi::Function::New(env, BitNDUnpack8));
  exports.Set(Napi::String::New(env, "BitNDPack128v32"), Napi::Function::New(env, BitNDPack128v32));
  exports.Set(Napi::String::New(env, "BitNDUnpack128v32"), Napi::Function::New(env, BitNDUnpack128v32));
  exports.Set(Napi::String::New(env, "BitNDPack128v16"), Napi::Function::New(env, BitNDPack128v16));
  exports.Set(Napi::String::New(env, "BitNDUnpack128v16"), Napi::Function::New(env, BitNDUnpack128v16));

  exports.Set(Napi::String::New(env, "BitND1Pack32"), Napi::Function::New(env, BitND1Pack32));
  exports.Set(Napi::String::New(env, "BitND1Unpack32"), Napi::Function::New(env, BitND1Unpack32));
  exports.Set(Napi::String::New(env, "BitND1Pack16"), Napi::Function::New(env, BitND1Pack16));
  exports.Set(Napi::String::New(env, "BitND1Unpack16"), Napi::Function::New(env, BitND1Unpack16));
  exports.Set(Napi::String::New(env, "BitND1Pack8"), Napi::Function::New(env, BitND1Pack8));
  exports.Set(Napi::String::New(env, "BitND1Unpack8"), Napi::Function::New(env, BitND1Unpack8));
  exports.Set(Napi::String::New(env, "BitND1Pack128v32"), Napi::Function::New(env, BitND1Pack128v32));
  exports.Set(Napi::String::New(env, "BitND1Unpack128v32"), Napi::Function::New(env, BitND1Unpack128v32));
  exports.Set(Napi::String::New(env, "BitND1Pack128v16"), Napi::Function::New(env, BitND1Pack128v16));
  exports.Set(Napi::String::New(env, "BitND1Unpack128v16"), Napi::Function::New(env, BitND1Unpack128v16));

  exports.Set(Napi::String::New(env, "BitNZPack32"), Napi::Function::New(env, BitNZPack32));
  exports.Set(Napi::String::New(env, "BitNZUnpack32"), Napi::Function::New(env, BitNZUnpack32));
  exports.Set(Napi::String::New(env, "BitNZPack16"), Napi::Function::New(env, BitNZPack16));
  exports.Set(Napi::String::New(env, "BitNZUnpack16"), Napi::Function::New(env, BitNZUnpack16));
  exports.Set(Napi::String::New(env, "BitNZPack8"), Napi::Function::New(env, BitNZPack8));
  exports.Set(Napi::String::New(env, "BitNZUnpack8"), Napi::Function::New(env, BitNZUnpack8));
  exports.Set(Napi::String::New(env, "BitNZPack128v32"), Napi::Function::New(env, BitNZPack128v32));
  exports.Set(Napi::String::New(env, "BitNZUnpack128v32"), Napi::Function::New(env, BitNZUnpack128v32));
  exports.Set(Napi::String::New(env, "BitNZPack128v16"), Napi::Function::New(env, BitNZPack128v16));
  exports.Set(Napi::String::New(env, "BitNZUnpack128v16"), Napi::Function::New(env, BitNZUnpack128v16));

  exports.Set(Napi::String::New(env, "EFanoEncode32"), Napi::Function::New(env, EFanoEncode32));
  exports.Set(Napi::String::New(env, "EFanoDecode32"), Napi::Function::New(env, EFanoDecode32));
  exports.Set(Napi::String::New(env, "EFano1Encode32"), Napi::Function::New(env, EFano1Encode32));
  exports.Set(Napi::String::New(env, "EFano1Decode32"), Napi::Function::New(env, EFano1Decode32));
  exports.Set(Napi::String::New(env, "EFanoEncode128v32"), Napi::Function::New(env, EFanoEncode128v32));
  exports.Set(Napi::String::New(env, "EFanoDecode128v32"), Napi::Function::New(env, EFanoDecode128v32));
  exports.Set(Napi::String::New(env, "EFano1Encode128v32"), Napi::Function::New(env, EFano1Encode128v32));
  exports.Set(Napi::String::New(env, "EFano1Decode128v32"), Napi::Function::New(env, EFano1Decode128v32));

  return exports;
}

NODE_API_MODULE(intcompressor, Init)
